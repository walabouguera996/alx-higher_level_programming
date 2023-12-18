#include <stdio.h>

void print_python_float(PyObject *obj)
{
    double val = 0;
    char *str = NULL;

    fflush(stdout);
    printf("[.] float object info\n");

    if (!PyFloat_CheckExact(obj))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    val = ((PyFloatObject *)obj)->ob_fval;
    str = PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    printf("  value: %s\n", str);
}

void print_python_bytes(PyObject *obj)
{
    Py_ssize_t size = 0, i = 0;
    char *str = NULL;

    fflush(stdout);
    printf("[.] bytes object info\n");

    if (!PyBytes_CheckExact(obj))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(obj);
    printf("  size: %zd\n", size);

    str = (assert(PyBytes_Check(obj)), (((PyBytesObject *)(obj))->ob_sval));
    printf("  trying string: %s\n", str);

    printf("  first %zd bytes:", size < 10 ? size + 1 : 10);
    while (i < size + 1 && i < 10)
    {
        printf(" %02hhx", str[i]);
        i++;
    }
    printf("\n");
}

void print_python_list(PyObject *obj)
{
    Py_ssize_t size = 0;
    PyObject *item;
    int i = 0;

    fflush(stdout);
    printf("[*] Python list info\n");

    if (PyList_CheckExact(obj))
    {
        size = PyList_GET_SIZE(obj);
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %lu\n", ((PyListObject *)obj)->allocated);

        while (i < size)
        {
            item = PyList_GET_ITEM(obj, i);
            printf("Element %d: %s\n", i, item->ob_type->tp_name);

            if (PyBytes_Check(item))
                print_python_bytes(item);
            else if (PyFloat_Check(item))
                print_python_float(item);

            i++;
        }
    }
    else
    {
        printf("  [ERROR] Invalid List Object\n");
    }
}
