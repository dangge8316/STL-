#pragma once
#include <set>
#include <iostream>

using namespace std;

template <class _Ty,
	class _Container = set<_Ty> >
	class sizeFilter
{
public:
	typedef sizeFilter<_Ty, _Container> myT;
	typedef typename _Container::size_type size_type;
	typedef typename _Container::value_type value_type;
	//默认构造函数
	sizeFilter() :c()
	{
		
	}
	//使用指定sizeFilter容器构造
	sizeFilter(const myT& _Right) :c(_Right.c)
	{

	}
	//使用指定容器类型构造
	sizeFilter(const _Container& cont) :c(cont)
	{

	}
	//赋值运算符重载
	myT& operator=(const myT& other)
	{
		c = other.c;
		return (*this);
	}
	//获取容器大小
	int size() const
	{
		return c.size();
	}
	//判断容器是否为空
	bool empty() const
	{
		return c.empty();
	}
	//插入元素
	bool insert(const value_type& element)
	{
		typename _Container::iterator cit = c.insert(c.begin(), element);
		if (cit != c.end())
		{
			cout << "插入" << element << "成功!" << endl;
			return true;
		}
		cout << "插入数据失败!";
		return false;
	}
	//删除元素
	bool erase(const value_type& element)
	{
		if (c.erase(element) > 0)
		{
			return true;
		}
		return false;
	}
	//获取最大值
	pair<value_type, bool> getMax()
	{
		//定义一个用于接收返回值的对组
		pair<value_type, bool> ret;
		if (c.size() > 0)
		{
			ret.first = *(--(c.end()));
			ret.second = true;
			cout << "该容器中最大值为:" << ret.first << endl;
			return ret;
		}
		ret.second = false;
		cout << "获取最大值失败,该容器中没有任何数据!" << endl;
		return ret;
	}
	//获取最小值
	pair<value_type, bool> getMin()
	{
		pair<value_type, bool> ret;
		if (c.size() > 0)
		{
			ret.first = *(c.begin());
			ret.second = true;
			cout << "该容器中最小值为:" << ret.first << endl;
			return ret;
		}
		ret.second = false;
		cout << "获取最小值失败,该容器中没有任何数据!" << endl;
		return ret;
	}

protected:
	_Container c;
};