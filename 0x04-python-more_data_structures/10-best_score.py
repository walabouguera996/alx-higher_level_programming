#!/usr/bin/python3
def best_score(a_dictionary):
    if a_dictionary is None:
        return None
    mv = 0
    mk = None
    for k, v in a_dictionary.items():
        if v > mv:
            mv = v
            mk = k
    return mk
