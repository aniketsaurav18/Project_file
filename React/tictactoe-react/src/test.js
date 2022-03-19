const gameArray = [1, 2, 3, 4, 5, 6, 7, 8, 9];

const checkTie = (gamearr) => {
  return !gamearr.some((index) => {
    console.log(index === gameArray[index - 1]);
    return index === gameArray[index - 1];
  });
};

const gamearr = ["X", "X", "X", "O", "O", "X", "X", "X", "O"];
console.log(checkTie(gamearr));
