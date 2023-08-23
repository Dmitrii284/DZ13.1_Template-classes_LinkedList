//#include <map>
//
//class Object
//{
//private:
//	int m_Data;
//public:
//	explicit Object(int data) : m_Data{ data } {}
//
//	void Show()
//	{
//		printf("%i", m_Data);
//	}
//};
//
//int main()
//{
//	std::map<int, Object*>map;
//	Object* object = new Object(10);
//	Object* object2 = new Object(20);
//	Object* object3 = new Object(30);
//
//	map.insert(std::make_pair(0, object));
//	map.insert(std::make_pair(1, object2));
//	map.insert(std::make_pair(2, object3));
//
//	for (const auto& element : map)
//		element.second->Show();
//	return 0;
//}

/** Шаблонные классы
Задание
Создать шаблонный класс динамической коллекции (связный список, очередь динамический
массив). За образец можете взять код репозиториев:
Динамический массив;https://github.com/varkmort/allocators-example/
Статический массив. https://github.com/varkmort/template_class



Создать шаблонный класс динамической коллекции связный список.
Обязятельными пунктаи задания являются следующие возможности коллекции:
размещение в себе элементов произвольного типа;
добавление и удаление элементов;
предоставление доступа к элементам массива;
возможность работы с колеекцией через range based for, sdt::size;
корректная передача по параметру в функции.
Дополнительные возможности:
работа независимо с хранением данных и с выделением памяти;
возможность удаления и вставки новых элементов в произвольные места коллекции.
Классы и функции реализованные вами опишите коментариями доступными системе doxigen.
Устанавливать Программу не требуется. В MS VS поддерживается внутреннее распознавание
таких комментариев. */

#include <iostream>
#include<vector>
#include <variant>
#include <cassert>
#include <iostream>
#include <string>
#include <variant>
#include <algorithm>
#include<map>

//
//
//template<class T>class LinkedList
//{
//private:
//
//	struct Node
//	{
//	public:
//		T data;
//		Node* next;
//	};
//
//	std::vector<Node*>m_Vector;
//
//	Node* m_Tail{ nullptr };
//
//	Node* m_Head{ nullptr };
//public:
//
//	auto begin() { return m_Vector.begin(); }
//
//	auto end() { return m_Vector.end(); }// Вернут конец вектора
//
//	// Функция добавление элемента в LinkedList
//	void PushBack(T data)
//	{
//		// Выделяем память для контролирования области жзни нашего объекта Node
//		Node* node = new Node{data};// Выделяем динамическую память под объект класса Node типа <T> и вызываем конструктор 
//		//Node<T>(data) с передачей в виде значения наш аргумент метода  PushBack(T data)
//		m_Vector.push_back(node);
//
//		//Когда мы вставим объект в вектор, нам вернётся итератор на этот объект и дальше мы с ним работаем
//		//auto node = m_Vector.emplace_back(new Node<T>(data));
//
//		// Проверяем пустой ли наш указатель на первый элемент списка
//		if (m_Tail == nullptr)
//		{
//			// Первый элемент будет и хвостом и Головой
//			m_Tail = node;
//			m_Head = node;
//			return;
//		}
//		// Если есть элементы то делаем между ними связь при добавлении элементов
//		
//		//2->3->4->5
//		m_Head->next = node;
//	}
//
//
//	//Функция добавление элемента в начало
//
//	//Функция поиска элемента по индексу
//
//	//Функция поиска элемента по значению
//
//	//Функция удаления элемента 
//
//	//Функция добавления элемента в произвольное место
//};
//
//int main()
//{
//	LinkedList < std::string>list;
//	list.PushBack("Hello");
//	list.PushBack("World");
//
//	for (auto el : list)
//		std::cout << el->data << std::endl;
//	return 0;
//}

//
//template<class T>class LinkedList
//{
//private:	
//
//	class Node
//	{
//	private:
//		T m_Data; //Шаблонный элемент
//		Node* m_Next; // Это указатель на следующий элемент в Списке LinkedList
//	public:
//
//		explicit Node(T data) : m_Data{ data } { }// Проинициализируем данные Node конструктором.  Если конструктор принимает в себя один аргумент он помеяается explicit
//
//		// Сделаем Get для m_Data и Get и Set для m_Next
//		T GetData() { return m_Data; }
//
//		Node* GetNext() { return m_Next; }// Пишем Node* т.к в private у нас уже определен тип указателя m_Next тип( Node)
//
//		void SetNext(Node* next) { m_Next = next; } // Полю m_Next приравниваем значение аргумента next функции SetNext
//	};
//
//	std::vector<Node*>m_Vector;
//
//	Node* m_Tail{ nullptr };
//
//	Node* m_Head{ nullptr };
//public:
//
//	auto begin() { return m_Vector.begin(); }
//
//	auto end() { return m_Vector.end(); }// Вернут конец вектора
//
//	// Функция добавление элемента в LinkedList
//	void PushBack(T data)
//	{
//		// Выделяем память для контролирования области жзни нашего объекта Node
//		Node* node = new Node{ data };// Выделяем динамическую память под объект класса Node типа <T> и вызываем конструктор 
//		//Node<T>(data) с передачей в виде значения наш аргумент метода  PushBack(T data)
//		m_Vector.push_back(node);
//
//		//Когда мы вставим объект в вектор, нам вернётся итератор на этот объект и дальше мы с ним работаем
//		//auto node = m_Vector.emplace_back(new Node<T>(data));
//
//		// Проверяем пустой ли наш указатель на первый элемент списка
//		if (m_Tail == nullptr)
//		{
//			// Первый элемент будет и хвостом и Головой
//			m_Tail = node;
//			m_Head = node;
//			return;
//		}
//		// Если есть элементы то делаем между ними связь при добавлении элементов
//
//		//2->3->4->5
//		m_Head->SetNext(node);
//	}
//
//
//	//Функция добавление элемента в начало
//
//	void PushFront(T data)
//	{
//		Node* node = new Node{ data };
//		m_Vector.insert(node);
//
//		if (m_Tail == nullptr)
//		{
//			m_Tail = node;
//			m_Head = node;
//			return;
//		}
//
//		//0->1->2->3->4->5->6
//		node->SetNext(m_Tail);// Нэкст у нового хвоста node будет равен старому хвосту m_Tail
//		m_Tail = node;// Тут просто новый хвост станоится на место старого хвоста
//	}
//
//	//Функция поиска элемента по индексу
//	Node* SearchElement(int index)
//	{
//		if( index > m_Vector.size())
//			return nullptr;
//		return m_Vector.at(index);		
//	}
//
//	//Функция поиска элемента по значению
//
//	//Функция удаления элемента 
//
//	//Функция добавления элемента в произвольное место
//};
//
//int main()
//{
//
//	LinkedList<std::string>list;
//	list.PushBack("Hello");
//	list.PushBack("World");
//	list.PushBack(10);
//	
//
//
//
//	for (auto el : list)
//		std::cout << el->GetData() << std::endl;
//	
//	std::cout << list.SearchElement(1)->GetData()<< std::endl;
//
//	for (auto it : list)
//		std::cout << it->GetData() << std::endl;
//
//	/*std::vector<int>vec{1, 2, 5};
//
//	std::cout << vec.at(3);*/
//	return 0;
//}


template<class T>class LinkedList
{
private:

	class Node
	{
	private:
		T m_Data; //Шаблонный элемент
		Node* m_Next{ nullptr }; // Это указатель на следующий элемент в Списке LinkedList
	public:

		explicit Node(T data) : m_Data{ data } { }// Проинициализируем данные Node конструктором.  Если конструктор принимает в себя один аргумент он помеяается explicit

		// Сделаем Get для m_Data и Get и Set для m_Next
		T GetData() { return m_Data; }

		Node* GetNext() { return m_Next; }// Пишем Node* т.к в private у нас уже определен тип указателя m_Next тип( Node)

		void SetNext(Node* next) { m_Next = next; } // Полю m_Next приравниваем значение аргумента next функции SetNext
	};

	std::variant<int, std::string>var;

	std::vector<Node*>m_Vector;

	Node* m_Tail{ nullptr };

	Node* m_Head{ nullptr };
public:
	T GetDataList() { return Node::GetData(); }

	auto begin() { return m_Vector.begin(); }

	auto end() { return m_Vector.end(); }// Вернут конец вектора

	// Функция добавление элемента в LinkedList
	void PushBack(T data)
	{
		// Выделяем память для контролирования области жзни нашего объекта Node
		Node* node = new Node{ data };// Выделяем динамическую память под объект класса Node типа <T> и вызываем конструктор 
		//Node<T>(data) с передачей в виде значения наш аргумент метода  PushBack(T data)
		m_Vector.push_back(node);

		//Когда мы вставим объект в вектор, нам вернётся итератор на этот объект и дальше мы с ним работаем
		//auto node = m_Vector.emplace_back(new Node<T>(data));

		// Проверяем пустой ли наш указатель на первый элемент списка
		if (m_Tail == nullptr)
		{
			// Первый элемент будет и хвостом и Головой
			m_Tail = node;
			m_Head = node;
			return;
		}
		// Если есть элементы то делаем между ними связь при добавлении элементов

		//2->3->4->5
		m_Head->SetNext(node);
	}


	//Функция добавление элемента в начало

	void PushFront(T data)
	{
		Node* node = new Node{ data };
		m_Vector.insert(node);

		if (m_Tail == nullptr)
		{
			m_Tail = node;
			m_Head = node;
			return;
		}

		//0->1->2->3->4->5->6
		node->SetNext(m_Tail);// Нэкст у нового хвоста node будет равен старому хвосту m_Tail
		m_Tail = node;// Тут просто новый хвост станоится на место старого хвоста
	}

	//Функция поиска элемента по индексу
	Node* SearchElement(int index)
	{
		if (index > m_Vector.size())
			return nullptr;
		return m_Vector.at(index);
	}

	//Функция поиска элемента по значению	
	Node* SearchElementValue(const T& value)
	{
		Node* returned_node = nullptr;

		std::any_of(m_Vector.begin(), m_Vector.end(), [&](Node* element)// any_of - это от куда( m_Vector.begin()), до куда
			//(  m_Vector.end()), и лямбда Выражение ([&](Node* element) )   Само выражение заканчивается тут ( }); )
			//m_Vector.begin() - здесь храняться у нас Ноды по этому мы делаем следующую проврку if (element->GetData() == value)
			{
				if (element->GetData() == value)// если наш element равняется аргументу функции value то ОК
				{
					returned_node = element;// returned_node это Node которую мы вернем 
					return true;
				}
				else
					return false;
			});

		return returned_node;// Возвращаемая Node Она может быть литбо nullptr либо значением которое мы нашли  element в  any_of
	}

	//Функция добавления элемента в произвольное место

	//Функция добавления элемента в произвольное место (У нас Элементы это Ноды - они находятся у нас в векторе, А значения они храняться в Нодах
	// А именно GetData() - тут храниться значение

	//Функция добавления элемента в произвольное место(Это значит добавляем Ноду в произвольное место)
	void AddElementByIndex(const T& element, int index)// Индекс index по которому мы вставляем элемент element
	{
		if (index < 0) { return; }

		if (index == m_Vector.size())// Если нашь index равен длинне вектора Нодов (Это означает что мы добавляем в конец вектора) 
		{
			m_Vector.emplace_back(new Node(static_cast<decltype(element)>("0")));// Добавляем в конец вектора 
			/**  Добавляем новую Ноду new Node в конец и вуктора(static_cast<decltype(element)>("0")) (Но для этого
			 сначало вызывем конструктор () "explicit Node(T data) :" и в нем и определяем тип нашего элемента decltype(element)
			 и с помощью static_cast приравниваем тип к нашему ("0")
			static_cast<int>(60.5); - Пример static_cast прировняет 60.5 к инту (тоесть из float к int
			*/
			auto x = m_Vector.end() - 2;// Находим предпоследний элемент
			(*x)->SetNext((*m_Vector.end() - 1));// Делаем связь предпоследнего элемента Х с последним элементом *m_Vector.end() - 1
			// Разименовывая его т.к мы работаем с указателями.
			m_Head = (*m_Vector.end() - 1);// и говорим что нашь m_Head - т.е последний элемент равен последнему элементу вектора
			//*m_Vector.end() - 1 а разименовываем его чтобы получить Ноду по адресу памяти 
		}
		//1->2->3->4
		if (index > m_Vector.size())
		{
			/**  В переменной count будет храниться количество 0 которое дополним в случае выхода зп ределы вектора */
			for (int count = index - m_Vector.size() - 1; count > 0; --count)
			{
				m_Vector.emplace_back(new Node(static_cast<decltype(element)>("0")));

			}
			m_Vector.emplace_back(new Node(element));


			return;
		}

		auto added = m_Vector.insert(m_Vector.begin() + index, new Node(element));

		m_Vector.at(index - 1)->SetNext(*added);

		(*added)->SetNext(m_Vector.at(index + 1));
	}
};

int main()
{
	LinkedList<std::string>list;
	list.PushBack("Hello");
	list.PushBack("World");

	/*for (auto el : list)
		std::cout << el->GetData() << std::endl;*/

		//std::cout << list.SearchElement(1)->GetData() << std::endl;
		//std::string a = "World";

		//std::cout << list.SearchElementValue(a)->GetData();
		// list.DeleteElement(1)->GetData();

	for (auto it : list)
		std::cout << it->GetData() << std::endl;

	list.AddElementByIndex("By By", 3);

	std::cout << std::endl << std::endl;

	for (auto it : list)
		std::cout << it->GetData() << std::endl;

	/*std::vector<int>vec{1, 2, 5};

	std::cout << vec.at(3);*/
	return 0;
}