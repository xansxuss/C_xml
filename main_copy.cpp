#include <iostream>
#include <string>
#include <fstream>
#include "string.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace std;
// int main(int argc, char const *argv[])
// {

//     // 读取xml
//     rapidxml::file<> fdoc("../test_xml.xml");
//     // cout << "fdoc:" << fdoc.data() << endl;
//     rapidxml::xml_document<> doc;
//     doc.parse<1>(fdoc.data());
//     // cout << "doc:" << doc << endl;

//     rapidxml::xml_node<> *root = doc.first_node();

//     // cout << "root:" << root->name() << endl;

//     rapidxml::xml_node<> *node1 = root->first_node();

//     // std::cout << node1->name() << std::endl;
//     rapidxml::xml_node<> *Employee = doc.allocate_node(rapidxml::node_element, "name");

//     return 0;
// }

static const int buf_len = 2048;
static char buf[buf_len] = {0};

void createXML(const char *file_name)
{
    // 1.DOM
    rapidxml::xml_document<> doc;

    // 2.node_declaration
    rapidxml::xml_node<> *declaration = doc.allocate_node(rapidxml::node_declaration);
    declaration->append_attribute(doc.allocate_attribute("version", "1.0"));
    declaration->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(declaration);

    // 3.node_pi
    rapidxml::xml_node<> *dec = doc.allocate_node(rapidxml::node_pi, doc.allocate_string("xml version=\"1.0\" encoding=\"utf-8\""));
    doc.append_node(dec);

    // 4.node_element
    rapidxml::xml_node<> *root = doc.allocate_node(rapidxml::node_element, "root");
    doc.append_node(root);

    // 5.node_comment
    rapidxml::xml_node<> *comment = doc.allocate_node(rapidxml::node_comment, 0, "这是一个注释节点");
    root->append_node(comment);

    rapidxml::xml_node<> *students = doc.allocate_node(rapidxml::node_element, "students");

    // 6.node_data
    rapidxml::xml_node<> *one_student = doc.allocate_node(rapidxml::node_element, "student");
    rapidxml::xml_node<> *name = doc.allocate_node(rapidxml::node_data, "node_name", "11");
    one_student->append_node(name);
    students->append_node(one_student);

    // 7.node_element with value
    rapidxml::xml_node<> *two_student = doc.allocate_node(rapidxml::node_element, "student", "22");
    students->append_node(two_student);

    // 8.set attribute
    rapidxml::xml_node<> *three_student = doc.allocate_node(rapidxml::node_element, "student", "33");
    students->append_node(three_student);
    three_student->append_attribute(doc.allocate_attribute("course", doc.allocate_string(buf)));
    three_student->append_attribute(doc.allocate_attribute("score", "98"));

    // 9.node_element without value
    rapidxml::xml_node<> *four_student = doc.allocate_node(rapidxml::node_element, "student");
    students->append_node(four_student);

    // 10.node_cdata
    rapidxml::xml_node<> *five_student = doc.allocate_node(rapidxml::node_cdata, "student", "55");
    students->append_node(five_student);

    // 11.node_cdata
    rapidxml::xml_node<> *six_student = doc.allocate_node(rapidxml::node_pi, "student", "66");
    students->append_node(six_student);

    // 12.node_cdata
    rapidxml::xml_node<> *seven_student = doc.allocate_node(rapidxml::node_doctype, "student", "77");
    students->append_node(seven_student);
    root->append_node(students);

    // 13.输出DOM到命令行
    std::cout << doc;

    // 14.输出DOM到文件
    // std::ofstream outfile(file_name, std::ios::out);
    // if (outfile)
    // {
    //     char *end = rapidxml::print(buf, doc, 0);
    //     *end = 0;
    //     outfile << buf;
    //     outfile.close();
    // }
}

int main()
{
    const char *file_name = "rapid.xml";
    createXML(file_name);
    return 0;
}