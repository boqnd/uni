const fs = require('fs');

const POPULATION_SIZE = 10;
const NUM_OF_QUEENS = 8;
const MUTATION_RATE = 0.05;
const PARENTS_RATIO = 0.5;
const MAX_FITNESS =
  NUM_OF_QUEENS * (NUM_OF_QUEENS-1) / 2;

var population = [];

// The fitness function calculates the number of queen pairs that do not attack each other.
function fitness(seq) {
  var score = 0;

  for (let row = 0; row < NUM_OF_QUEENS; row++) {
      col = seq[row];

      for (let other_row = 0;
        other_row < NUM_OF_QUEENS;
        other_row++) {
          if (other_row == row)
            continue;
          if (seq[other_row] == col)
            continue;
          if (other_row + seq[other_row] == row + col)
            continue;
          if (other_row - seq[other_row] == row - col)
            continue;
          score++;
      }
  }

  return score/2;
}

// initialPopulation function generates POPULATION_SIZE number of states with random getetic values, the fitnes of each state is calculated and they are stored sorted in the `population` variable.
function initialPopulation() {
  for (let p = 0; p < POPULATION_SIZE; p++) {
    var state = { seq: [] };

    for (let i = 0; i < NUM_OF_QUEENS; i++) {
      var num = Math.floor(
        Math.random()*NUM_OF_QUEENS
      ) + 1;
      state.seq.push(num);
    }

    state.fitness = fitness(state.seq);
    population.push(state);
  }
  population.sort(
    (a, b) => (a.fitness < b.fitness ? 1 : -1)
  );
}

// mutate function takes a state and return the mutated state. Every genetic value of the state has a MUTATION_RATE chance of being changed with a random value.
function mutate(seq) {
  for (let row = 0; row < seq.length; row++) {
      if (Math.random() < MUTATION_RATE) {
        seq[row] = Math.floor(
          Math.random()*NUM_OF_QUEENS
        ) + 1;
      }
  }
  return seq;
}

// getParents returns the first POPULATION_SIZE*PARENTS_RATIO states with the highest fitness value.
function getParents() {
  const parents = population.slice(
    0,
    POPULATION_SIZE*PARENTS_RATIO
  );

  return parents;
}

// getCouples takes a list of parents and returns a list of every combination of two parents.
function getCouples(parents) {
  var couples = []
  parents.map(
      (v, i) => parents.slice(i+1).map( w => {
        let curr = [];
        curr.push(v);
        curr.push(w);
        couples.push(curr);
      } )
  );

  return couples;
}

// crossover takes a couple (a list of two parent states), generates a random cross_point, the parents are crossed, the offsprings are mutated and a list of the two offsprings is returned.
function crossover(couple) {
  var cross_point = Math.floor(
    Math.random()*NUM_OF_QUEENS
  );
  offsprings = [];

  offsprings.push(
    couple[0].seq.slice(0,cross_point).concat(
      couple[1].seq.slice(cross_point)
    )
  );
  offsprings.push(
    couple[1].seq.slice(0,cross_point).concat(
      couple[0].seq.slice(cross_point)
    )
  );

  offsprings = offsprings.map(
    offspr => {
      let seq = mutate(offspr);
      return {
        seq,
        fitness: fitness(seq)
      }
    }
  );

  return offsprings;
}

// nextGeneration is executing getParents, getCouples and crossover, generating a new generation of states then sorting them by their fitness and storing the best POPULATION_SIZE of them in the `population` variable.
function nextGeneration() {
  const parents = getParents();
  const couples = getCouples(parents);

  const nextGen = []

  couples.forEach(couple => {
    var offsprings = crossover(couple);
    offsprings.forEach(offspring => {
      nextGen.push(offspring);
    })
  });

  nextGen.sort(
    (a, b) => (a.fitness < b.fitness ? 1 : -1)
  );
  population = nextGen.slice(0, POPULATION_SIZE);
}

// findSolution is executing nextGeneration and comparing the best fitness score of each population to MAX_FITNESS until MAX_FITNESS is reached. Every step is written in a file with the solution on the last row.
function findSolution() {
  let writeStream = fs.createWriteStream(
    `solutions/EightQueensSolution_${Date.now()}.txt`
  );

  initialPopulation();

  let counter = 0;
  while (population[0].fitness < MAX_FITNESS) {
    writeStream.write(
      `>> generation: ${counter} - fitness: ${population[0].fitness} - current state:\n`
    );
    console.log(
      `>> generation: ${counter} - fitness: ${population[0].fitness} - current state:\n`
    );
    writeStream.write(population[0].seq + '\n\n');

    nextGeneration();
    counter++;
  }

  writeStream.write(`\n\nSOLUTION:\n`);
  writeStream.write(population[0].seq + '\n');
  writeStream.end();
}

findSolution();