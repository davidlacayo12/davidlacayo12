# Welcome to my local code repo : Personal Learning 

## For installing all dependencies, use: 
### pip install -r .\requirements.txt

## For updating the dependencies file, use:
### pip freeze > requirements.txt

## For logging into gcloud use:
### gcloud auth application-default login

## For auto formatting: 
### black, mypy
### black <directory>

## see pipeline process with: 
### 1. activate the virtual environment
####    Go to root of environment and run: 
####    python3 -m venv venv
####    source venv/bin/activate
####    pip install --upgrade pip setuptools
####    pip install -e .
### 2. install deps: 
####    pip install -r requirements/extras/tests.txt -r requirements/build.txt
### 3. run tests with:
####    pytest -v
### 4. run a build with: 
####    python3 -m build
#####       this will make a dist/ folder with the source code package (tar.gz file) and the wheel  (*.  whl file)
#####       these are what get published to artifactory so the package is available for pip install


## Installing test package into fiml repo 
### activate the venv for the fidelity-crime repo
### in that venv, use pip install -e but install the directory of the testing package (ex: pip install -e ../cna-mlops-testing/)

## For cleaning up origin/... branches:
### git fetch --all --prune

## install repo for local testing 
### pip install -e path/to/folder

## deleting local tags:
### git tag -d <tag-name>
