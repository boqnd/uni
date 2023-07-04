function findElements(a, e, i, L, w, Omega, myu, t) {
  i = i * Math.PI / 180;
  let n = Math.sqrt(1 / Math.pow(a, 3));
  let to = ((w - L) / n) * Math.PI / 180;

  let gamma = 1 + myu;
  let capL = myu * Math.sqrt(gamma * a);
  let capG = capL * Math.sqrt(1 - Math.pow(e, 2));
  let capTheta = capG * Math.cos(i);

  let l = n * (t * 2 * Math.PI - to);
  let g = (w - Omega) * Math.PI / 180;
  let theta = Omega * Math.PI / 180;
  let H = -myu * gamma / (2 * a);

  let FirstPoincare11 = capL;
  let FirstPoincare12 = capL - capG;
  let FirstPoincare13 = capG - capTheta;
  let FirstPoincare21 = l + g + theta;
  let FirstPoincare22 = -g - theta;
  let FirstPoincare23 = -theta;

  // L
  let SecondPoincare11 = FirstPoincare11;

  // ݜ銠 - this is epsilon
  let SecondPoincare12 = Math.sqrt(2 * (capL - capG)) * Math.cos(g + theta);

  // p
  let SecondPoincare13 = Math.sqrt(2 * (capG - capTheta)) * Math.cos(theta);

  // λ = l + g + ݜ㊠ (this is lower theta)
  let SecondPoincare21 = FirstPoincare21;

  // η
  let SecondPoincare22 = -Math.sqrt(2 * (capL - capG)) * Math.sin(g + theta);

  // q
  let SecondPoincare23 = -Math.sqrt(2 * (capG - capTheta)) * Math.sin(theta);

  console.log({capL, capG, capTheta, l, g, theta, H, FirstPoincare11, FirstPoincare12, FirstPoincare13, FirstPoincare21, FirstPoincare22, FirstPoincare23, SecondPoincare11, SecondPoincare12, SecondPoincare13, SecondPoincare21, SecondPoincare22, SecondPoincare23})
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
   findElements(
       nasaData[i][0], nasaData[i][1], nasaData[i][2],
       nasaData[i][3], nasaData[i][4], nasaData[i][5],
       nasaData[i][6], time
   );
}
