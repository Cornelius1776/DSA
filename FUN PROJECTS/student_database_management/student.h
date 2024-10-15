#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

class Student
{
    std::string _first_name;
    std::string _middle_name;
    std::string _last_name;
    std::string _department;
    int _matric;

    // Database data structure
    std::vector<Student> _students;

public:
    Student() {}  // constructor
    ~Student() {} // Destructor

    // Methods
    // Add students to the database
    void add_students()
    {
        Student new_student;
        std::cout << "Enter first name: ";
        std::getline(std::cin, new_student._first_name);
        std::cout << "Enter middle name: ";
        std::getline(std::cin, new_student._middle_name);
        std::cout << "Enter last name: ";
        std::getline(std::cin, new_student._last_name);
        std::cout << "Enter department: ";
        std::getline(std::cin, new_student._department);
        std::cout << "Enter matric number: ";
        std::cin >> new_student._matric;
        _students.push_back(new_student);
        std::cout << "Student added succesfully!" << std::endl;
    }

    // Draw underline
    void underline()
    {
        int length = 90;
        for (int i = 0; i <= length; i++)
        {
            std::cout << "_";
        }
        std::cout << std::endl;
    }

    // View database
    void view_database()
    {
        int serial_No = 1;
        int spacing = 35;
        std::cout << std::left;
        std::cout << "S/N   ";
        std::cout << std::setw(spacing) << "Name " << std::setw(spacing) << "Department "
                  << "Matric .No\n";
        underline();
        for (const Student &student : _students)
        {
            std::cout << serial_No << ".    ";
            std::cout << std::setw(spacing) << (student._first_name + " " + student._middle_name + " " + student._last_name)
                      << std::setw(spacing) << student._department
                      << student._matric << std::endl;
            serial_No++;
        }
        std::cout << std::endl;
    }

    // Display student info
    void display_all_students()
    {
        std::cout << std::endl;
        if (_students.empty())
        {
            std::cout << "Database is empty!" << std::endl;
        }
        else
        {
            view_database();
        }
    }

    // Delete students
    void delete_student(int matric_No)
    {
        auto student_to_delete = std::find_if(_students.begin(), _students.end(),
                                              [matric_No](const Student &student_object)
                                              { return student_object._matric == matric_No; });

        std::cout << "Are you sure you want to delete this student permanently ?\nyes or no: ";
        std::string answer;

        std::cin >> answer;

        if (student_to_delete != _students.end() && answer == "yes")
        {
            _students.erase(student_to_delete);
            std::cout << "Student with matric " << matric_No << " has been deleted successfully!" << std::endl;
        }
        else
        {
            std::cout << "Student with matric " << matric_No << " not found" << std::endl;
        }
    }

    // Update students data
    void update_student(int matric_No)
    {
        auto student_to_update = std::find_if(_students.begin(), _students.end(),
                                              [matric_No](const Student &student_object)
                                              { return student_object._matric == matric_No; });

        if (student_to_update != _students.end())
        {
            int option;
            std::cout << "1. firstname   2.middlename  3.lastname  4.department  5.matric" << std::endl;
            std::cout << "What information would you like to update? ";
            std::cin >> option;
            switch (option)
            {
            case 1:
                std::cin.ignore();
                std::cout << student_to_update->_first_name << std::endl;
                std::cout << "Update first name: ";
                std::getline(std::cin, student_to_update->_first_name);
                break;
            case 2:
                std::cin.ignore();
                std::cout << student_to_update->_middle_name << std::endl;
                std::cout << "Update middle name: ";
                std::getline(std::cin, student_to_update->_middle_name);
                break;
            case 3:
                std::cin.ignore();
                std::cout << student_to_update->_last_name << std::endl;
                std::cout << "Update last name: ";
                std::getline(std::cin, student_to_update->_last_name);
                break;
            case 4:
                std::cin.ignore();
                std::cout << student_to_update->_department << std::endl;
                std::cout << "Update department: ";
                std::getline(std::cin, student_to_update->_department);
                break;
            case 5:
                std::cin.ignore();
                std::cout << student_to_update->_matric << std::endl;
                std::cout << "Update matric number: ";
                std::cin >> student_to_update->_matric;
                break;
            default:
                std::cout << "Invalid entry" << std::endl;
                break;
            }

            std::cout << "Student updated successfully" << std::endl;
        }
        else
        {
            std::cout << "Student not found!" << std::endl;
        }
    }

    // Open database
    void open_database()
    {
        Student student;
        int option;
        int matric_No;
        std::cout << "\nWelcome to LAUTECH student database management system" << std::endl;

        while (option != 5)
        {

            std::cout << "Options: " << std::endl;
            std::cout << "1. Add new student" << std::endl;
            std::cout << "2. Display students" << std::endl;
            std::cout << "3. Delete student" << std::endl;
            std::cout << "4. Update student" << std::endl;
            std::cout << "5. Save changes" << std::endl;

            std::cout << "Select: ";
            std::cin >> option;
            switch (option)
            {
            case 1:
                std::cin.ignore(); // To deal with buffers
                student.add_students();
                break;
            case 2:
                student.display_all_students();
                break;
            case 3:
                std::cout << "Enter matric number of the student to be deleted: ";
                std::cin >> matric_No;
                student.delete_student(matric_No);
                break;
            case 4:
                std::cin.ignore();
                std::cout << "Enter matric number of the student to be updated: ";
                std::cin >> matric_No;
                student.update_student(matric_No);
                break;
            case 5:
                std::cout << "Saving Changes...closing database" << std::endl;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
        };
    }
};

#endif // !STUDENT_H
