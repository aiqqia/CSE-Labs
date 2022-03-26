import pandas as pd

Students = {"Name": ["Ayush Goyal", "Dipesh Singh", "Shiv Baratam"], "Height": ["6'3", "4'5", "5'11"],"Qualifications": ["BTECH", "Mid-School", "12th Pass"]}

new = pd.DataFrame.from_dict(Students)
print(new)
address = ["Kolkata", "Delhi", "Bengaluru"]
new["Address"] = address
print(new)