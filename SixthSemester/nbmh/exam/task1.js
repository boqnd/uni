function norm(vector) {
  let sumOfSquares = 0;
  for (let i = 0; i < vector.length; i++) {
      sumOfSquares += Math.pow(vector[i], 2);
  }
  return Math.sqrt(sumOfSquares);
}

function solvePlanet(a, e, i, L, w, Omega, miu, t) {
  let tita = Omega * Math.PI / 180;
  let g = (w - Omega) * Math.PI / 180;
  i = i * Math.PI / 180;

  let Tita = [
      [Math.cos(tita), -Math.sin(tita), 0],
      [Math.sin(tita), Math.cos(tita), 0],
      [0, 0, 1]
  ];

  let I = [
      [1, 0, 0],
      [0, Math.cos(i), -Math.sin(i)],
      [0, Math.sin(i), Math.cos(i)]
  ];

  let G = [
      [Math.cos(g), -Math.sin(g), 0],
      [Math.sin(g), Math.cos(g), 0],
      [0, 0, 1]
  ];

  let Q = multiplyMatrices(multiplyMatrices(Tita, I), G);

  let gama = 1 + miu;
  let n = Math.sqrt(gama / Math.pow(a, 3));
  let to = ((w - L) / n) * Math.PI / 180;
  let l = n * (t * 2 * Math.PI - to);
  let u = l + e * Math.sin(l + e * Math.sin(l + e * Math.sin(l)));

  let r = multiplyMatrixVector(Q, [a * (Math.cos(u) - e), a * Math.sin(u) * Math.sqrt(1 - Math.pow(e, 2)), 0]);
  let v = multiplyMatrixVector(Q, [-Math.sin(u), Math.cos(u) * Math.sqrt(1 - Math.pow(e, 2)), 0]);
  v = multiplyVectorScalar(v, a * n / (1 - e * Math.cos(u)));

  console.log('V =', v);
  console.log('R =', r);
  console.log('Norm V =', norm(v));
  console.log('Norm R =', norm(r));
}

function multiplyMatrices(m1, m2) {
  let result = [];
  for (let i = 0; i < m1.length; i++) {
      result[i] = [];
      for (let j = 0; j < m2[0].length; j++) {
          let sum = 0;
          for (let k = 0; k < m1[0].length; k++) {
              sum += m1[i][k] * m2[k][j];
          }
          result[i][j] = sum;
      }
  }
  return result;
}

function multiplyMatrixVector(matrix, vector) {
  let result = [];
  for (let i = 0; i < matrix.length; i++) {
      let sum = 0;
      for (let j = 0; j < vector.length; j++) {
          sum += matrix[i][j] * vector[j];
      }
      result.push(sum);
  }
  return result;
}

function multiplyVectorScalar(vector, scalar) {
  let result = [];
  for (let i = 0; i < vector.length; i++) {
      result.push(vector[i] * scalar);
  }
  return result;
}

let nasaData = [
  [0.387, 0.205, 7.004, 252.250, 77.457, 48.330, 1 / 6023600],
  [0.723, 0.006, 3.394, 181.979, 131.602, 76.679, 1 / 408523],
  [1, 0.016, 0, 100.464, 102.937, 0, 1 / 328900.5],
  [1.523, 0.093, 1.849, -4.553, -23.943, 49.559, 1 / 3098708],
  [5.202, 0.048, 1.304, 34.396, 14.728, 100.473, 1 / 1047.34],
  [9.536, 0.053, 2.485, 49.954, 92.598, 113.662, 1 / 3497.8],
  [19.189, 0.047, 0.772, 313.238, 170.954, 74.016, 1 / 22902.9],
  [30.069, 0.008, 1.770, -55.120, 44.964, 131.784, 1 / 19402],
  [39.482, 0.248, 17.140, 238.929, 224.068, 110.303, 1 / 135000000]
];

let time = 2.4777549624;

for (let i = 0; i < 9; i++) {
  console.log('Planet №', i + 1);
  solvePlanet(
      nasaData[i][0], nasaData[i][1], nasaData[i][2],
      nasaData[i][3], nasaData[i][4], nasaData[i][5],
      nasaData[i][6], time
  );
}
