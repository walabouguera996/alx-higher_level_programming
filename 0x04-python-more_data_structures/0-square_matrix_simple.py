#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    return list(map(lambda sm: list(map(lambda e: e**2, sm)), matrix))
