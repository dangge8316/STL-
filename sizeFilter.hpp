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
	//Ĭ�Ϲ��캯��
	sizeFilter() :c()
	{
		
	}
	//ʹ��ָ��sizeFilter��������
	sizeFilter(const myT& _Right) :c(_Right.c)
	{

	}
	//ʹ��ָ���������͹���
	sizeFilter(const _Container& cont) :c(cont)
	{

	}
	//��ֵ���������
	myT& operator=(const myT& other)
	{
		c = other.c;
		return (*this);
	}
	//��ȡ������С
	int size() const
	{
		return c.size();
	}
	//�ж������Ƿ�Ϊ��
	bool empty() const
	{
		return c.empty();
	}
	//����Ԫ��
	bool insert(const value_type& element)
	{
		typename _Container::iterator cit = c.insert(c.begin(), element);
		if (cit != c.end())
		{
			cout << "����" << element << "�ɹ�!" << endl;
			return true;
		}
		cout << "��������ʧ��!";
		return false;
	}
	//ɾ��Ԫ��
	bool erase(const value_type& element)
	{
		if (c.erase(element) > 0)
		{
			return true;
		}
		return false;
	}
	//��ȡ���ֵ
	pair<value_type, bool> getMax()
	{
		//����һ�����ڽ��շ���ֵ�Ķ���
		pair<value_type, bool> ret;
		if (c.size() > 0)
		{
			ret.first = *(--(c.end()));
			ret.second = true;
			cout << "�����������ֵΪ:" << ret.first << endl;
			return ret;
		}
		ret.second = false;
		cout << "��ȡ���ֵʧ��,��������û���κ�����!" << endl;
		return ret;
	}
	//��ȡ��Сֵ
	pair<value_type, bool> getMin()
	{
		pair<value_type, bool> ret;
		if (c.size() > 0)
		{
			ret.first = *(c.begin());
			ret.second = true;
			cout << "����������СֵΪ:" << ret.first << endl;
			return ret;
		}
		ret.second = false;
		cout << "��ȡ��Сֵʧ��,��������û���κ�����!" << endl;
		return ret;
	}

protected:
	_Container c;
};