from google.cloud import storage
import pandas as pd
import tempfile
import pathlib

client = storage.Client()
bucket = client.get_bucket("bucket_name")
blob = bucket.get_blob("path_to_bucket.xlsx")

with tempfile.TemporaryDirectory() as tdir:
    tpath = pathlib.Path(tdir).resolve()
    dpath = (
        tpath / "path_to_bucket.xlsx"
    )
    dpath_ext = dpath.name.split(".")[-1]  ## get file extension

    if dpath_ext not in ["xlsx", "xlsm"]:
        raise TypeError("Not an Excel File.")

    blob.download_to_filename(dpath)

    with open("table.json", "w") as fd:
        fd.write((pd.read_excel(dpath).to_json(orient="records", indent=4)))