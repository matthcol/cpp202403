import numpy as np
import matplotlib.pyplot as plt

data = np.random.normal(21.0, 3.0, 1_000_000)
plt.hist(data, bins=1000)
plt.show()