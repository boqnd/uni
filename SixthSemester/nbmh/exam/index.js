function toRadians(degrees) {
  return degrees * (Math.PI / 180);
}

function toHours(radians) {
  return radians * (12 / Math.PI);
}

function calculatePlanetPositions(date) {
  const year = date.getUTCFullYear();
  const month = date.getUTCMonth() + 1;
  const day = date.getUTCDate();
  const hour = date.getUTCHours();
  const minute = date.getUTCMinutes();
  const second = date.getUTCSeconds();

  // Calculate the number of Julian centuries since J2000.0
  const jd = 367 * year
    - Math.floor(7 * (year + Math.floor((month + 9) / 12)) * 0.25)
    + Math.floor(275 * month / 9)
    + day + 1721013.5
    + ((second / 60 + minute) / 60 + hour) / 24
    - 2451545.0;
  const T = jd / 36525;

  // Orbital elements for the planets (in degrees)
  const elements = [
    // Mercury
    [252.250906, 149472.6746358, 0.000005377, -0.0000000022],
    // Venus
    [181.979801, 58517.8156760, 0.00000165, -0.000000002],
    // Earth
    [100.466449, 35999.3728519, 0.000005967, 0.0],
    // Mars
    [355.433275, 19140.2993313, 0.000002610, -0.000000003],
    // Jupiter
    [34.351519, 3036.3027748, 0.000027293, 0.000000086],
    // Saturn
    [50.077444, 1223.5110686, 0.00021004, -0.000000017],
    // Uranus
    [314.055005, 429.8640561, 0.00030434, -0.000000643],
    // Neptune
    [304.348665, 219.8833092, 0.00030926, 0.000000018]
  ];

  // Ecliptic obliquity
  const epsilon = 23.439291 - 0.0130042 * T;

  const planetNames = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune'];

  // Calculate positions for each planet
  for (let i = 0; i < elements.length; i++) {
    const [L0, L1, L2, L3] = elements[i];

    // Mean longitude
    const longitude = L0 + L1 * T + L2 * Math.pow(T, 2) + L3 * Math.pow(T, 3);
    const longitudeInRange = (longitude % 360 + 360) % 360;

    // Calculate right ascension and declination
    const alpha = Math.atan2(Math.cos(toRadians(epsilon)) * Math.sin(toRadians(longitude)), Math.cos(toRadians(longitude)));
    const alphaHours = toHours(alpha);
    const delta = Math.asin(Math.sin(toRadians(epsilon)) * Math.sin(toRadians(longitude)));

    // Print the results
    console.log(planetNames[i] + ':');
    console.log('Longitude:', longitudeInRange, 'degrees');
    console.log('Right Ascension:', alphaHours, 'hours');
    console.log('Declination:', delta, 'degrees');
    console.log('-----------------------');
  }
}

// Usage example: Calculate positions for June 23, 2002 at 00:00:00 UTC
const date = new Date(Date.UTC(2001, 9, 14, 0, 0, 0));
console.log('Date: ', date);
console.log('-----------------------');
calculatePlanetPositions(date);
