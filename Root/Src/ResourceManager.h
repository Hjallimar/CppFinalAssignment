#pragma once
#include <unordered_map>
#include <SDL.h>
#include <sstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>

template<class T>
struct Value;

class ResourceManager
{
public:
	
private:
	struct ValueBase
	{
		public:
			ValueBase();
			~ValueBase();
	};

	template <class T>
	struct Value : public ValueBase
	{
		Value<T>(T* newValue) { value = newValue; }
		~Value() { delete value; }

		T* value;
		T* GetValue()
		{
			return value;
		}
	};

	std::string base;
	std::unordered_map<std::string, std::shared_ptr<ValueBase>> resourses;

public:
	ResourceManager()
	{
		resourses = std::unordered_map<std::string, std::shared_ptr<ValueBase>>();
		resourses.reserve(10);
	}

	~ResourceManager()
	{
		resourses.clear();
	}

	//void AssignBase(std::string newBase) {
	//	base = newBase;
	//}

	//
	//void AddItemFromPath(const std::string path) 
	//{
	//	std::ofstream newItem = std::ofstream(base + "/" + path);
	//	Value<std::ofstream> value = Value<std::ofstream>(&newItem);
	//	resourses.emplace(path, value);
	//}

	//template<class T>
	//void AddItem(const std::string path, T* newItem)
	//{
	//	Value<T> value = Value<T>(newItem);
	//	resourses.emplace(path, value);
	//}
	//
	//template <class T>
	//std::shared_ptr<T> GetItem(const std::string path)
	//{
	//	Value<T>* value = dynamic_cast<Value<T>*>(resourses[path]);
	//	return  std::make_shared<value->GetValue()>;
	//}
};

