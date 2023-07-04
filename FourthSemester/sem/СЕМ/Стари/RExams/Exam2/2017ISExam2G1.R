#EXAM 2 G1
A=1; B=1; C=1; D=1

time_var=c(92.34, 94.84, 84.63, 76.63, 86.92, 103.41, 95.77, 73.04, 84.22, 86.68, 81.23, 96.64, 77.19, 69.68,
95.39, 91.89, 86.59, 81.48, 88.98, 86.91, 82.65, 84.94, 83.44, 85.28, 72.58)

mean(time_var)
sigma=10

alpha=0.89+D/100
qnorm((1-alpha)/2, mean = mean(time_var), sd = sigma/sqrt(length(time_var)))
qnorm(1-(1-alpha)/2, mean = mean(time_var), sd = sigma/sqrt(length(time_var)))


##### Cancer data
cancer_data=c(124, 42, 25, 45, 412, 51, 1112, 46, 103, 876, 146, 340, 396)
wilcox.test(cancer_data, mu = 100, alternative = "greater", conf.level = 0.01 + D/100)


##### Nail polish
samp1=c(7.83+A, 3.9+B, 13.89+C, 13.12+D, 10.34, 16.85, 12.62, 10.52, 7.21, 6.76, 8.19, 16.19, 11.92, 8.1, 8.01)
samp2=c(9.66 + A, 9.38 + B, 10.35 + C, 11.05 + D, 11.28, 11.32, 10.16, 8.78, 9.58, 9.63, 9.76, 10.57)

t.test(samp1, samp2, var.equal = FALSE, conf.level = 0.01 + D/100, alternative = "greater")








