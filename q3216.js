/**
 * @param {string} s
 * @return {string}
 */
var getSmallestString = function (s) {
  let result = s;
  for (let i = 1; i < s.length; i++) {
    const c = s[i];
    const c2 = s[i - 1];
    if (Number(c) % 2 === Number(c2) % 2) {
      if (c < c2) {
        result = s.substring(0, i - 1);
        console.log(result);
        result += c;
        result += c2;
        result += s.substring(i + 1, s.length);
        return result;
      }
    }
  }
  return result;
};
