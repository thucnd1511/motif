function getAllSubstrings(str, k) {
  const substrings = [];

  for (let i = 0; i < str.length; i++) {
    for (let j = i + 1; j <= str.length; j++) {
      const substring = str.slice(i, j);
      if (substring.length == k) {
        substrings.push(substring);
      }
    }
  }

  return substrings;
}

function getAllSubstringsFromMultipleStrings(strings, k) {
  const allSubstrings = [];

  for (const str of strings) {
    const substrings = getAllSubstrings(str, k);
    allSubstrings.push(substrings);
  }

  return allSubstrings;
}

function findCommonElementsInArrays(arrays) {
  if (!Array.isArray(arrays) || arrays.length < 2) {
    return [];
  }

  const commonElements = [];

  // Sử dụng mảng đầu tiên làm mảng mẫu để so sánh với các mảng khác
  const referenceArray = arrays[0];

  for (const element of referenceArray) {
    // Kiểm tra xem phần tử có tồn tại trong tất cả các mảng khác không
    if (arrays.slice(1).every(arr => arr.includes(element))) {
      commonElements.push(element);
    }
  }

  return commonElements;
}
function getDef(strings, h) {
  const substrings = [];
  for (const str of strings) {
    const substring = getAllSubstrings(str, h);
    substrings.push(substring);
  }
  return substrings;
}
function result(uniqueArray, dataDef) {
  let result = [];
  for (const data of dataDef) {
    for (const str of uniqueArray) {
      let elementsWithSubstring = []
      elementsWithSubstring = data.filter(element => element.includes(str));
      result = result.concat(elementsWithSubstring);
    }
  }

  return [...new Set(result)];
}