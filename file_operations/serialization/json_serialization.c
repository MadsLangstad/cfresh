/**
 * @file json_serialization.c
 * @brief Demonstrates JSON serialization and deserialization in C using the json-c library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Added for strdup
#include <json-c/json.h>

/**
 * @brief Serializes an Employee structure to a JSON string.
 * 
 * @param id Employee ID.
 * @param name Employee Name.
 * @param salary Employee Salary.
 * @return char* Serialized JSON string. The caller is responsible for freeing the memory.
 */
char* serialize_employee_json(int id, const char *name, float salary) {
    struct json_object *jobj = json_object_new_object();

    json_object_object_add(jobj, "id", json_object_new_int(id));
    json_object_object_add(jobj, "name", json_object_new_string(name));
    json_object_object_add(jobj, "salary", json_object_new_double(salary));

    const char *jstr = json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PRETTY);
    char *result = strdup(jstr); // Duplicate the string to return
    json_object_put(jobj); // Free the json_object

    return result;
}

/**
 * @brief Deserializes a JSON string to extract Employee information.
 * 
 * @param json_str The JSON string representing an Employee.
 */
void deserialize_employee_json(const char *json_str) {
    struct json_object *jobj = json_tokener_parse(json_str);
    if (jobj == NULL) {
        fprintf(stderr, "Failed to parse JSON.\n");
        return;
    }

    struct json_object *jid, *jname, *jsalary;

    if (json_object_object_get_ex(jobj, "id", &jid)) {
        printf("ID: %d\n", json_object_get_int(jid));
    } else {
        printf("ID not found.\n");
    }

    if (json_object_object_get_ex(jobj, "name", &jname)) {
        printf("Name: %s\n", json_object_get_string(jname));
    } else {
        printf("Name not found.\n");
    }

    if (json_object_object_get_ex(jobj, "salary", &jsalary)) {
        printf("Salary: %.2f\n", json_object_get_double(jsalary));
    } else {
        printf("Salary not found.\n");
    }

    json_object_put(jobj); // Free the json_object
}

int main(void) {
    int id = 1;
    const char *name = "Alice Smith";
    float salary = 70000.0f;

    // Serialize to JSON
    char *json_str = serialize_employee_json(id, name, salary);
    if (json_str == NULL) {
        fprintf(stderr, "Failed to serialize employee to JSON.\n");
        return EXIT_FAILURE;
    }

    printf("Serialized JSON:\n%s\n\n", json_str);

    // Deserialize from JSON
    printf("Deserialized JSON:\n");
    deserialize_employee_json(json_str);

    free(json_str); // Free the duplicated string

    return EXIT_SUCCESS;
}
