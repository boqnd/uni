library(UsingR)

data <- read.csv("/Users/boyandonchev/school/uni/FourthSemester/R/Project/data.csv")

View(data)

barplot(height = prop.table(table(data$Вашият.пол))*100)
barplot(height = prop.table(table(data$Имате.ли.шофьорска.книжка.))*100)
barplot(height = prop.table(table(data$На.колко.години.сте.))*100)
barplot(height = prop.table(table(data$Колко.пъти.сте.претърпявали.ПТП.зад.волана.))*100)
barplot(height = prop.table(table(data$Според.вас.средностатистическият.мъж.по.добър.шофьор.ли.е.от.средностатистическата.жена.))*100)
barplot(height = prop.table(table(data$Съгласни.ли.сте.с.факта..че.мъжете.са.по.безотговорни.на.пътя..а.жените.са.по.дезориентирани.))*100)
barplot(height = prop.table(table(data$Според.вас.мъжете.или.жените.зад.волана.са.по.опасни.за.останалите.участници.в.движението.))*100)
barplot(height = prop.table(table(data$На.колко.промила.трябва.да.е.един.мъж..за.да.кара.по.зле.от.жена.))*100)

pie(table(data$На.колко.промила.трябва.да.е.един.мъж..за.да.кара.по.зле.от.жена.))

pie(table(data$Съгласни.ли.сте.с.факта..че.мъжете.са.по.безотговорни.на.пътя..а.жените.са.по.дезориентирани.))


mode <- function(vec) {
  uniqv <- unique(vec)
  uniqv[which.max(tabulate(match(vec, uniqv)))]
}

age <- sort(c(data$На.колко.години.сте.))
summary(age)

mean(age) #Средна стойност
median(age) #Медиана
mode(age) #Мода
var(age) #Дисперсия
sd(age) #Стандартно отклонение


hist(age)
abline(v = mean(age), col = "pink")
abline(v = median(age), col = "red")


boxplot(a)

qqplot(age, rnorm(n = 10^2, mean = mean(age), sd = sd(age))
, main = "Нормалн разпределение")
abline(a = 0, b = 1)


age <- c(data$На.колко.години.сте.)
ptp <- c(data$Колко.пъти.сте.претърпявали.ПТП.зад.волана.)

rho <- round(cor(age, ptp), 3) #коефициент на корелация
par(mfrow = c(1, 1))
plot(age, ptp)

cor(age, ptp)
cor.test(age, ptp, method = "spearman")

better <- c(data$Според.вас.средностатистическият.мъж.по.добър.шофьор.ли.е.от.средностатистическата.жена.)

boxplot(age~better)

dan <- c(data$Според.вас.мъжете.или.жените.зад.волана.са.по.опасни.за.останалите.участници.в.движението.)
prom <- c(data$На.колко.промила.трябва.да.е.един.мъж..за.да.кара.по.зле.от.жена.)
boxplot(prom~dan)

bartlett.test(prom~dan)
kruskal.test(prom~dan)




