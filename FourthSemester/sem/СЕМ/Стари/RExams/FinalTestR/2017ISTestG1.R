
##### Zadacha 1
data_corns=read.csv("Corns.csv")
data_corns[1:5,]
head(data_corns)

summary(data_corns)

table(data_corns$Corns)
table(data_corns$state)
prop.table(table(data_corns$Corns))
prop.table(table(data_corns$state))

table(data_corns$Corns, data_corns$state)
barplot(table(data_corns$Corns, data_corns$state), beside = T)
barplot(table(data_corns$state, data_corns$Corns), beside = T)

boxplot(data_corns$Price ~ data_corns$Corns)

hist(data_corns$Price[data_corns$Corns=="Hazelnuts"])

plot(data_corns$Price[data_corns$state=="Roasted"], data_corns$L[data_corns$state=="Roasted"])

plot(data_corns$Price[data_corns$Corns=="Hazelnuts"], data_corns$L[data_corns$Corns=="Hazelnuts"])

mu=mean(data_corns$L[data_corns$Corns=="Sunflower"])
sigma=sd(data_corns$L[data_corns$Corns=="Sunflower"])

c(mu-qnorm(0.92)*sigma, mu+qnorm(0.92)*sigma)


chisq.test(data_corns$Price, p = dnorm(data_corns$Price, mean(data_corns$Price), sd(data_corns$Price)), rescale.p = T)

##### Zadacha 2
pnorm(4, 3, 1)

pnorm(2, 3, 1, lower.tail = F)

pnorm(5, 3, 1) - pnorm(2, 3, 1)

qnorm(0.9 + pnorm(1,3,1), 3, 1)






