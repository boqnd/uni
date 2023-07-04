input = read.csv("C:/Users/Toni/Downloads/pokemon.csv", header=TRUE)

set.seed(61797)

randomIndexes = c(sample({1:705}, 600, replace = FALSE))
pokemonData = input[randomIndexes, ]

head(pokemonData)
# Name - качествени
# Type1 - качествени
# Type2 - качествени
# Attack - количествени (непрекъснати)
# Defence - количествени (непрекъснати)
# Height - количествени (непрекъснати)
# Weight - количествени (непрекъснати)

summary(pokemonData)

attach(pokemonData)
print(pokemonData[Height == max(Height),])
print(pokemonData[Weight == min(Weight),])

print(pokemonData[Attack + Defense > 220,])

nrow(pokemonData[(Type1 == "Dragon" | Type2 == "Dragon" | Type1 == "Flying" | Type2 == "Flying") & Height > 1,])

hist(pokemonData[Type2 != "", c("Weight")], probability = TRUE)
lines(density(pokemonData[Type2 != "", c("Weight")]))
# данните не са разположени симетрично

boxplot(pokemonData[Type1 == "Normal",c("Weight")], pokemonData[Type1 == "Fighting",c("Weight")])
# при покемоните с първичен тип Normal има 7 outliner-и, докато при тези с тип Fighting- само 2,
# всички от които над съответните медиани.
# Покемоните с тип Fighting средно тежат повече, от тези с тип NOrmal

plot(Height, Weight)

cor(Height, Weight)

abline(lm(Weight ~ Height))
# съществува средно силна линейна връзка между височината и теглото на покемоните
nums = lm(Weight ~ Height)$coefficients

print( nums[2]*2.1 + nums[1])
# Height 
# 115.349 







