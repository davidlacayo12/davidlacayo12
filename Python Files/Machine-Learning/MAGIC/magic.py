import numpy as np
import pandas as pd
import matplotlib.pyplot as plt 
from sklearn.preprocessing import StandardScaler
from imblearn.over_sampling import RandomOverSampler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report

#Dataset found from UCI machine learning repository 
#loss = -1/N * sum(Y_real * log(Y_predicted) + (1-Y_real) * log(1-Y_predicted))
#Euclidean distance: d = sqrt( (x1-x2)^2 + (y1-y2)^2 )
#Bayes' Rule: P(A|B) = ( P(B|A) * P(A) ) / P(B)
#                       likelihood times prior, over evidence 
#

cols = ["Length", "width", "fSize", "fConc", "fConcl", "fAsym", "fM3Long", "FM3Trans", "fAlpha", "fDist", "class"]
df = pd.read_csv("/Users/davidlacayo/Desktop/Personal-Github/Python Files/Machine-Learning/MAGIC/magic04.data", names=cols) 

df["class"] = (df["class"] == "g").astype(int)
df.head()

for label in cols[:-1]:
    plt.hist(df[df["class"] == 1][label], color = 'blue', label = 'gamma', alpha = 0.7, density = True)
    plt.hist(df[df["class"] == 0][label], color = 'red', label = 'hadron', alpha = 0.7, density = True)
    plt.title(label)
    plt.ylabel("Probability")
    plt.xlabel(label)
    plt.legend()
    plt.show()

#Train, validation and test datasets

train, valid, test = np.split(df.sample(frac=1), [int(0.6*len(df))], [int(0.8*len(df))])

def scale_dataset(dataframe, oversample=False):
    x = dataframe[dataframe.columns[:-1]].values
    y = dataframe[dataframe.columns[-1]].values
    
    scaler = StandardScaler()
    x = scaler.fit_transform(x)
    
    if(oversample):
        ros = RandomOverSampler()
        x,y = ros.fit_resample(x,y)
    
    #take two arrays and horizontally stack them together 
    data = np.hstack((x,np.reshape(y, (-1, 1))))
    
    return data, x, y

train, x_train, y_train = scale_dataset(train, oversample=True)
valid, x_valid, y_valid = scale_dataset(valid, oversample=False)
test, x_test, y_test = scale_dataset(test, oversample= False)

knn_model = KNeighborsClassifier(n_neighbors= 3)
knn_model.fit(x_train, y_train)
KNeighborsClassifier(n_neighbors=1)

y_pred = knn_model.predict(x_test)
print(classification_report(y_test, y_pred))