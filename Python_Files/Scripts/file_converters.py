import pandas as pd 
import yaml

def xlsx2csv(file_name: str, sheet_name: str | int = 0):
    file = pd.read_excel(file_name, sheet_name=sheet_name)
    file.to_csv("conversion.csv", index=None)


def xlsx2json(file_name: str, sheet_name: str | int = 0):
    file = pd.read_excel(file_name, sheet_name=sheet_name)
    file.to_json("conversion.json", index=None)

# This needs to be tailored to the columns of the excel file
def xlsx2yaml(file_name: str, sheet_name: str | int = 0):
    file = pd.read_excel(file_name, sheet_name=sheet_name)

    data = file.groupby('Category')[['Category', 'Value']].apply(lambda x: x.set_index('Category').to_dict(orient='records')).to_dict()
    with open('conversion.yaml', 'w') as f:
        yaml.dump(data, f)
