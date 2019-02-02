import pandas as pd
import pydataset

titanic = pydataset.data('titanic')

print("\n\nColunas: ", titanic.columns)
print("Tipos da coluna class: ", titanic['class'].describe())

print('Bytes: ',titanic['class'].nbytes)

titanic['class'] = titanic['class'].astype('category')

print('Bytes após categorização: ',titanic['class'].nbytes)