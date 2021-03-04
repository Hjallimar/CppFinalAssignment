#pragma once
#include <unordered_map>
#include <SDL.h>
#include <iostream>

template<class T>
struct Value;

class ResourceManager
{
private:
	struct ValueBase
	{
		public:
			virtual void OutPut(std::ostream& osStream) = 0;

			template <class T>
			T* GetValue() = 0;
	};

	template <class T>
	struct Value : public ValueBase
	{
	private:
		T* value;
	public:
		Value<T>(T* newValue) : value(newValue){}
		~Value() { delete value; }

		virtual T* GetValue()
		{
			return value;
		}

		void output(std::ostream& osStream, ValueBase& head)
		{
			head.OutPut(osStream);
			return osStream;
		}
	};

	std::unordered_map<std::string, ValueBase*> resourcecs;
public:
	ResourceManager()
	{
		resourcecs = std::unordered_map<std::string, ValueBase*>();
		resourcecs.reserve(10);
	}

	~ResourceManager()
	{
		resourcecs.clear();
	}

	template <class T>
	void AddItem(std::string name, T* item)
	{
		Value<T> val = Value<T>(item);
		resourcecs.emplace(name, &val);
	}

	template <class T>
	T* GetItem(std::string path)
	{
		return resourcecs.at(path)->OutPut();
	}
};

