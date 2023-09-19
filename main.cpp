#include <iostream>
#include <string>
#include <fstream>
#include "string.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace std;

void create(rapidxml::xml_document<> &doc)
{
    // root
    rapidxml::xml_node<> *declaration = doc.allocate_node(rapidxml::node_declaration);
    declaration->append_attribute(doc.allocate_attribute("version", "1.0"));
    declaration->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(declaration);
    // fisrt node
    rapidxml::xml_node<> *EmployeeData = doc.allocate_node(rapidxml::node_element, "EmployeeData");
    doc.append_node(EmployeeData);
    // secend node
    rapidxml::xml_node<> *Employees = doc.allocate_node(rapidxml::node_element, "Employee");
    Employees->append_attribute(doc.allocate_attribute("student_type", "Part-time"));

    // thrid node
    rapidxml::xml_node<> *one_Employee = doc.allocate_node(rapidxml::node_element, "Name");
    rapidxml::xml_node<> *name = doc.allocate_node(rapidxml::node_data, "Name", "andy");
    one_Employee->append_node(name);
    Employees->append_node(one_Employee);
    EmployeeData->append_node(Employees);

    // rapidxml::xml_node<> *two_Employee = doc.allocate_node(rapidxml::node_element, "Name", "Tom");
    // Employees->append_node(two_Employee);

    // EmployeeData->append_node(Employees);
}

int main()
{

    const char *file_name = "./test.xml";
    rapidxml::xml_document<> doc;
    create(doc);
    cout << doc << endl;
    std::ofstream out(file_name);

    out << doc;
    out.close();

    return 0;
}