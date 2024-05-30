#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>


class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> 
inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
    public:
        virtual ~Component() {}
        Entity* entity;
        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}
};

class Entity
{
    public:
        void update()
        {
            for (auto &c : components) c->update();
        }
        void draw()
        {
            for (auto &c : components) c->draw();
        }
        bool isActive() const { return active; }
        void destroy() { active = false; }

        // Returns true if the entity has a Component of type T
        template <typename T> 
        bool hasComponent() const
        {
            return componentBitSet[getComponentTypeID<T>()];
        }

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs)
        {
            // Create a component of type T and name it c.
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> u_ptr { c };
            components.emplace_back(std::move(u_ptr));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitSet[getComponentTypeID<T>()] = true;
            c->init();

            return *c; // Return reference to the component added
        }

        // Prevent this function from modifying member variables
        template <typename T>
        T& getComponent() const
        {
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;
        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
};


class Manager
{
    public:
        void update()
        {
            for (auto &e : entities) e->update();
        }
        void draw()
        {
            for (auto &e : entities) e->draw();
        }
        void refresh()
        {
            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entity> &myEntity)
            {
                return !myEntity->isActive();
            }),
            std::end(entities));
        }
        Entity& addEntity()
        {
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr { e };
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
    private:
        std::vector<std::unique_ptr<Entity>> entities;
};
