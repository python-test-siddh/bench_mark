#include <Python.h>
#include <stdio.h>


static PyObject *foo_bar(PyObject *self, PyObject *args)
{
if (!PyArg_ParseTuple(args, ""))
return NULL;
long long a = 100234234;  long long b = 22342342;  long long c = 341342;
for(int i = 1; i <= 10000000; i++){
a = (a * a * b)%c;
b = (a * b * b)%c;
}
return Py_BuildValue("L", a+b);
}




static PyMethodDef FooMethods[] = {
{"calc",  foo_bar, METH_VARARGS},
{NULL, NULL}  /* Sentinel */
};

static struct PyModuleDef foo_bar_module = {
    PyModuleDef_HEAD_INIT,
    "benchmark",
    "Python interface for the fputs C library function",
    -1,
    FooMethods
};




PyMODINIT_FUNC PyInit_benchmark(void) {
    return PyModule_Create(&foo_bar_module);
}
