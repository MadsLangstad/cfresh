/**
 * @file xml_serialization.c
 * @brief Demonstrates XML serialization and deserialization in C using the libxml2 library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Added for strncpy
#include <libxml/parser.h>
#include <libxml/tree.h>

/**
 * @brief Serializes an Employee structure to an XML file.
 * 
 * @param id Employee ID.
 * @param name Employee Name.
 * @param salary Employee Salary.
 * @param filename The name of the XML file to create.
 */
void serialize_employee_xml(int id, const char *name, float salary, const char *filename) {
    xmlDocPtr doc = NULL;
    xmlNodePtr root_node = NULL, employee_node = NULL;

    // Initialize the library and check potential ABI mismatches
    LIBXML_TEST_VERSION

    // Create a new document, a node and set it as the root node
    doc = xmlNewDoc(BAD_CAST "1.0");
    root_node = xmlNewNode(NULL, BAD_CAST "Employees");
    xmlDocSetRootElement(doc, root_node);

    // Create an Employee node
    employee_node = xmlNewChild(root_node, NULL, BAD_CAST "Employee", NULL);

    // Add ID, Name, and Salary as child nodes
    char id_str[10];
    sprintf(id_str, "%d", id);
    xmlNewChild(employee_node, NULL, BAD_CAST "ID", BAD_CAST id_str);

    xmlNewChild(employee_node, NULL, BAD_CAST "Name", BAD_CAST name);

    char salary_str[20];
    sprintf(salary_str, "%.2f", salary);
    xmlNewChild(employee_node, NULL, BAD_CAST "Salary", BAD_CAST salary_str);

    // Save the document to a file
    if (xmlSaveFormatFileEnc(filename, doc, "UTF-8", 1) == -1) {
        fprintf(stderr, "Error saving XML file.\n");
        xmlFreeDoc(doc);
        xmlCleanupParser();
        exit(EXIT_FAILURE);
    }

    printf("Serialized XML to '%s'.\n", filename);

    // Free the document
    xmlFreeDoc(doc);

    // Cleanup function for the XML library.
    xmlCleanupParser();
}

/**
 * @brief Deserializes an XML file to extract Employee information.
 * 
 * @param filename The name of the XML file to parse.
 */
void deserialize_employee_xml(const char *filename) {
    xmlDocPtr doc;
    xmlNodePtr root_element, employee_node, node;

    // Initialize the library and check potential ABI mismatches
    LIBXML_TEST_VERSION

    // Parse the file and get the DOM
    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Could not parse XML file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get the root element node
    root_element = xmlDocGetRootElement(doc);

    // Iterate through Employee nodes
    for (employee_node = root_element->children; employee_node; employee_node = employee_node->next) {
        if (employee_node->type == XML_ELEMENT_NODE && 
            xmlStrcmp(employee_node->name, BAD_CAST "Employee") == 0) {

            int id = 0;
            char name[100] = {0};
            float salary = 0.0f;

            for (node = employee_node->children; node; node = node->next) {
                if (node->type == XML_ELEMENT_NODE) {
                    if (xmlStrcmp(node->name, BAD_CAST "ID") == 0) {
                        id = atoi((const char *)xmlNodeGetContent(node));
                    } else if (xmlStrcmp(node->name, BAD_CAST "Name") == 0) {
                        strncpy(name, (const char *)xmlNodeGetContent(node), sizeof(name) - 1);
                    } else if (xmlStrcmp(node->name, BAD_CAST "Salary") == 0) {
                        salary = atof((const char *)xmlNodeGetContent(node));
                    }
                }
            }

            printf("ID: %d\n", id);
            printf("Name: %s\n", name);
            printf("Salary: %.2f\n\n", salary);
        }
    }

    // Free the document
    xmlFreeDoc(doc);

    // Cleanup function for the XML library.
    xmlCleanupParser();
}

int main(void) {
    int id = 2;
    const char *name = "Bob Johnson";
    float salary = 80000.0f;
    const char *filename = "employee.xml";

    // Serialize to XML
    serialize_employee_xml(id, name, salary, filename);

    // Deserialize from XML
    printf("\nDeserialized XML:\n");
    deserialize_employee_xml(filename);

    return EXIT_SUCCESS;
}
