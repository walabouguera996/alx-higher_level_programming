#!/bin/bash

echo "Hi Boss wala bouguera,  Enter your commit message"
read message


git add .
git commit -m "$message"
git push
