#Black-body radiation
import numpy as np 
import matplotlib.pyplot as plt 
#------------------------------------------------------------------------
#计算500K和800K黑体的光谱辐射出射度
def planck_formula(wavelength,      #波长
                   temperature,     #温度
                   c1=3.7414*10**8, #c1常量
                   c2=1.43879*10**4 #c2常量
                    ):
    return (c1/wavelength**5)*(1/(np.e**(c2/wavelength/temperature)-1))
#得到取样点以及输出取样点对应的值
wavelength_limit = np.linspace(0.001,100,100000)
out_500 = planck_formula(wavelength_limit,500)
out_800 = planck_formula(wavelength_limit,800)
plot_500 = plt.plot(wavelength_limit,out_500,label='500K')
plot_800 = plt.plot(wavelength_limit,out_800,label='800K')
#绘图
plt.xlim(0,20)
plt.ylim(0,8000)
plt.xlabel('wavelength: μm')
plt.ylabel('spectral radiant emission: w/(cm^2 * μm)')
plt.title('Blackbody spectral radiant emission curve:')
plt.legend()
plt.show()
