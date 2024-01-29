// 2. Опишите класс «студенческая group».
// Предусмотрите возможность: работы с переменным числом Студентов; поиска studentа по какому-либо признаку (например, по фамилии, дате рождения или номеру телефона); до-бавления или удаления записей; сортировки по разным полям.
// Разработайте программу, демонстрирующую работу с этим классом.
// Программа должна содержать меню, позволяющее осуществить проверку всех методов класса.

// 3 Абдул Икрамов Икрамович 3 3 Улук Жайлообеков Жайлообекович 4 3 Даурен Алтынбеков Алтынбекович 5 3
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
  string name;
  string surname;
  string patronymic;
  int group;
  int cours;

  Student() {}

  Student(string name, string surname, string patronymic, int group, int cours)
  {
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->group = group;
    this->cours = cours;
  }
};

void displayStudents(const vector<Student> &students)
{
  cout << "\nТаблица студентов:\n";
  cout << "------------------------------------------------------------------------\n";
  cout << "| Имя | Фамилия | Отчество | Группа | Курс |\n";
  cout << "------------------------------------------------------------------------\n";

  if (students.empty())
  {
    cout << "Студентов нет" << endl;
  }
  else
  {
    for (const auto &student : students)
    {
      cout << "|" << student.name << "|" << student.surname << "|" << student.patronymic << "|" << student.group << "| " << student.cours << "|\n";
    }
  }

  cout << "------------------------------------------------------------------------\n";
}

int main()
{
  vector<Student> students;
    bool exitProgram = false;
  cout << "Введите количество студентов: ";
  int n;
  cin >> n;

  // Ввод информации для каждого студента
  for (int i = 0; i < n; i++)
  {
    cout << "Введите данные для студента " << i + 1 << ":" << endl;
    Student newStudent;
    cout << "Имя: ";
    cin >> newStudent.name;

    cout << "Фамилия: ";
    cin >> newStudent.surname;

    cout << "Отчество: ";
    cin >> newStudent.patronymic;

    cout << "Группа: ";
    cin >> newStudent.group;

    cout << "Курс: ";
    cin >> newStudent.cours;

    students.push_back(newStudent);
  }

while (!exitProgram)
  {
  cout << "Введите действие над студентами " << endl;
  cout << "1 - добавление" << endl;
  cout << "2 - удаление" << endl;
  cout << "3 - поиск" << endl;
  cout << "4 - сортировка" << endl;
  cout << "5 - выход" << endl;

  int action;
  cin >> action;

  switch (action)
  {
  case 1:
    {
      // Добавление нового студента
      Student newStudent;
      cout << "Введите данные для нового студента:" << endl;
      cout << "Имя: ";
      cin >> newStudent.name;

      cout << "Фамилия: ";
      cin >> newStudent.surname;

      cout << "Отчество: ";
      cin >> newStudent.patronymic;

      cout << "Группа: ";
      cin >> newStudent.group;

      cout << "Курс: ";
      cin >> newStudent.cours;

      students.push_back(newStudent);
    }
    break;

  case 2:
    {
      // Удаление студента по фамилии
      if (!students.empty())
      {
        cout << "Введите фамилию студента для удаления: ";
        string surnameToDelete;
        cin >> surnameToDelete;

        int indexToDelete = -1; // Индекс студента для удаления, -1 означает, что студент не найден
        for (int i = 0; i < students.size(); ++i)
        {
          if (students[i].surname == surnameToDelete)
          {
            indexToDelete = i;
            break;
          }
        }

        if (indexToDelete != -1)
        {
          // Удаление студента
          for (int i = indexToDelete; i < students.size() - 1; ++i)
          {
            students[i] = students[i + 1];
          }
          students.pop_back();

          cout << "Студент успешно удален." << endl;
        }
        else
        {
          cout << "Студент с указанной фамилией не найден." << endl;
        }
      }
      else
      {
        cout << "Студентов нет для удаления." << endl;
      }
    }
    break;

  case 3:
    {
      // Поиск студента по фамилии
      if (!students.empty())
      {
        cout << "Введите фамилию студента для поиска: ";
        string surnameToSearch;
        cin >> surnameToSearch;

        bool found = false;
        for (const auto &student : students)
        {
          if (student.surname == surnameToSearch)
          {
            cout << "Студент найден:\n";
            displayStudents({student});
            found = true;
            break;
          }
        }

        if (!found)
        {
          cout << "Студент с указанной фамилией не найден." << endl;
        }
      }
      else
      {
        cout << "Студентов нет для поиска." << endl;
      }
    }
    break;

  case 4:
    // Сортировка студентов по фамилии (пузырьковая сортировка)
    if (!students.empty())
    {
      for (int i = 0; i < students.size() - 1; ++i)
      {
        for (int j = 0; j < students.size() - i - 1; ++j)
        {
          if (students[j].surname > students[j + 1].surname)
          {
            // Обмен элементов
            swap(students[j], students[j + 1]);
          }
        }
      }
      cout << "Студенты успешно отсортированы по фамилии." << endl;
    }
    else
    {
      cout << "Студентов нет для сортировки." << endl;
    }
    break;
    case 5:
      exitProgram = true;
      break;
  default:
    cout << "Некорректный ввод" << endl;
    break;
  }

  // Вывод информации о студентах
  displayStudents(students);
}
  return 0;
}
