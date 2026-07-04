import matplotlib.pyplot as plt


n=[10,100,1000,2000,10000,20000,100000,200000]

bubble= [0,0,0.002588,0.006852,0.147663,0.471675,13.8863,60.8128]
selection=[0,0,0.000997,0.003276,0.131728,0.352325,6.69469,26.9322]
insertion=[0,0,0,0.002008,0.038942,0.150604,3.81995,15.1325]

merge=[0,0,0,0,0.001999,0.004997,0.134201,0.596811]
quick=[0,0,0,0,0.001494,0.000996,0.007997,0.013975]


plt.plot(n,bubble,label="Bubble Sort")
plt.plot(n,selection,label="Selection Sort")
plt.plot(n,insertion,label="Insertion Sort")
plt.plot(n,merge,label="Merge Sort")
plt.plot(n,quick,label="Quick Sort")

plt.legend()
plt.title("N vs Time")
plt.savefig('plot.png')
plt.show()