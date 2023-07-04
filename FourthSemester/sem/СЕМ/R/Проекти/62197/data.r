#Данните за проекта
name <- c('Ter Stegen', 'Semedo', 'Pique', 'Umtiti', 'Alba', 'Artur', 'De Jong', 'Rakitic', 'Griezmann', 'Messi', 'Suarez', 'Courtois', 'Carvajal', 'Ramos', 'Varane', 'Mendy', 'Casemiro', 'Modric', 'Kroos', 'Isco', 'Hazard', 'Benzema', 'Dembele', 'Ronaldo', 'Neymar', 'Mbappe', 'Salah', 'Robertson', 'Sane', 'De Bruyne', 'Mane', 'Icardi', 'Verratti', 'Marquinos', 'Di Maria', 'van Djik', 'Allison', 'Firmino', 'Aguero', 'Silva', 'Ederson', 'De Ligt', 'Ramsey', 'Arnold', 'Matuidi')
age <- c(25, 22, 30, 25, 27, 22, 20, 31, 30, 31, 32, 27, 28, 31, 26, 22, 25, 33, 28, 27, 29, 30, 21, 34, 27, 20, 27, 26, 23, 27, 27, 26, 27, 25, 31, 28, 27, 28, 31, 25, 26, 19, 29, 20, 32)
rating <- c(7.17, 7.06, 7.34, 7.17, 7.05, 7.01, 7.35, 7.04, 6.96, 7.75, 6.63, 7.14, 6.96, 6.74, 7.24, 7.00, 6.79, 6.85, 6.85, 7.18, 7.11, 7.13, 7.05, 6.96, 7.34, 7.58, 7.40, 7.35, 7.25, 7.13, 7.03, 7.23, 7.1, 6.8, 6.94, 7.43, 7.2, 6.96, 6.68, 7.24, 6.9, 6.74, 6.91, 7.11, 6.8)
value <-c(90, 40, 35, 45, 50, 72, 85, 35, 130, 120, 50, 55, 50, 25, 70, 80, 63, 20, 57, 60, 150, 40, 100, 90, 180, 200, 155, 150, 100, 130, 120, 75, 70, 60, 55, 100, 80, 80, 100, 65, 70, 75, 60, 70, 30)
team <- c('Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona','Barcelona', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Real Madrid', 'Barcelona', 'Juventus', 'PSG', 'PSG', 'Liverpool', 'Liverpool', 'Man City', 'Man City', 'Liverpool', 'PSG', 'PSG', 'PSG', 'PSG', 'Liverpool', 'Liverpool', 'Liverpool', 'Man City', 'Man City', 'Man City', 'Juventus', 'Juventus', 'Liverpool', 'Juventus' )

players <- data.frame(
    name, age, rating, value, team
)

#настройка за позициониране на графика
op <- par(mar=c(6,4.5,2,2))


#Първоначален анализ на отделните колони

#barplot, който показва разпределението по отбори
barplot(table(players$team), col=rainbow(7), las = 2, ylab="Amount of players", main = "Amount of players in the different teams")

#boxplot, който показва разпределението на възрастта
boxplot(players$age, notch = TRUE, horizontal = TRUE, col='blue', xaxp=c(15,35,20), las = 2, main= "Players Age")
#histogram, която показва разпределнието на възрастта
hist(players$age, breaks=20, xlim=c(15, 35), col=rainbow(7), main="Players' age", xlab="Age")

#boxplot, който показва разпределението на средния рейтинг
boxplot(players$rating, notch = TRUE, horizontal = TRUE, col='blue', xaxp=c(5,9,80), las = 2, main="Players Average Rating")
#histogram, която показва разпределнието на средния рейтинг
hist(players$rating, breaks=10, col=rainbow(7), main = "Players' rating", xlab="Rating")

#boxplot, който показва разпределението на стойността
boxplot(players$value, notch = TRUE, horizontal = TRUE, col='blue', xaxp=c(0, 210,30), las = 2, main="Players Value", xlab="million euro")
#histogram, която показва разпределнието на стойността
hist(players$value, xlim=c(0,200), breaks = 15, col=rainbow(7), main="Players' value", xlab = "Value in millions of euro")


#Анализ спрямо категорийната колона

#barplot, който показва възрастта на играчи по отбори
barplot(table(players$team, players$age), col=rainbow(6), beside=TRUE, las=2, main="Amount of players at given age in different teams", ylab="Amount", xlab="Age")
legend("topright", legend=levels(players$team), fill = rainbow(6), cex = 0.65)
#boxplot, който показва разпределението на възрастта на играчите по отбори 
boxplot(age~team, data=players, las=2, col=rainbow(6), main="Age distribution in different teams", ylab="Age")
#anova one way test
anova_one_way <- aov(age~team, data = players)
summary(anova_one_way)

#barplot, който показва рейтинга на играчи по отбори
barplot(table(players$team, players$rating), col=rainbow(6), beside=TRUE, main="Rating amount in different teams", ylab="Amount", xlab="Rating")
legend("topright", legend=levels(players$team), fill = rainbow(6), cex = 0.6)
#boxplot, който показва разпределението на възрастта на играчите по отбори 
boxplot(rating~team, data=players, las=2, col=rainbow(6),  main="Rating distribution in different teams", ylab="Rating")
#anova one way test
anova_one_way <- aov(rating~team, data = players)
summary(anova_one_way)

#histogram, който показва цената на играчи по отбори
barplot(table(players$team, players$value), col=rainbow(6), beside=TRUE, las=2, main="Value amount in different teams", ylab="Amount", xlab="Value")
legend("topright", legend=levels(players$team), fill = rainbow(6), cex = 0.63)
#boxplot, който показва разпределението на цената на играчите по отбори 
boxplot(value~team, data=players, las=2, col=rainbow(6), main="Value distribution in different teams", ylab="Value")
#anova one way test
anova_one_way <- aov(value~team, data = players)
summary(anova_one_way)


#Сравняване на числовите колони една с друга

#сравняване на колони age & rating
plot(players$age, players$rating, xaxp=c(15, 40, 25), las=2, main = "Player age relation with player rating", ylab="Player rating", xlab="Player age")
abline(lm(rating ~ age, data=players), col="red", lwd=3)

tmp <- cor(players$age, players$rating, method = "pearson")
text(x = 32.75, y = 7.7, labels = paste0("Pearson's rho:", round(tmp, 2)), cex=0.75, col = "blue")

tmp <- cor(players$age, players$rating, method = "spearman")
text(x = 32.55, y = 7.6, labels = paste0("Spearman's rho:", round(tmp, 2)), cex=0.73, col = "brown")

tmp <- cor(players$age, players$rating, method = "kendall")
text(x = 32.75, y = 7.5, labels = paste0("Kendall's rho:", round(tmp, 2)), cex=0.75, col = "purple")

#сравняване на колони rating & value
plot(players$value, players$rating, xaxp=c(20, 200, 12), las=2, main = "Player value relation with player rating", ylab="Player rating", xlab="Player value (in million euro)")
abline(lm(rating ~ value, data=players), col="red", lwd=3)

tmp <- cor(players$value, players$rating, method = "pearson")
text(x = 180, y = 6.9, labels = paste0("Pearson's rho:", round(tmp, 2)), cex=0.75, col = "blue")

tmp <- cor(players$value, players$rating, method = "spearman")
text(x = 180, y = 6.8, labels = paste0("Spearman's rho:", round(tmp, 2)), cex=0.75, col = "brown")

tmp <- cor(players$value, players$rating, method = "kendall")
text(x = 180, y = 6.7, labels = paste0("Kendall's rho:", round(tmp, 2)), cex=0.75, col = "purple")

#сравняване на колони value & age
plot(players$value, players$age, xaxp=c(20, 200, 18), las=2, main = "Player age relation with player value", xlab="Player value (in million euro)", ylab="Player age")
abline(lm(age ~ value, data=players), col="red", lwd=3)

tmp <- cor(players$age, players$value, method = "pearson")
text(x = 180, y = 33.5, labels = paste0("Pearson's rho:", round(tmp, 2)), cex=0.75, col = "blue")

tmp <- cor(players$age, players$value, method = "spearman")
text(x = 180, y = 32.5, labels = paste0("Spearman's rho:", round(tmp, 2)), cex=0.75, col = "brown")

tmp <- cor(players$age, players$value, method = "kendall")
text(x = 180, y = 31.5, labels = paste0("Kendall's rho:", round(tmp, 2)), cex=0.75, col = "purple")


