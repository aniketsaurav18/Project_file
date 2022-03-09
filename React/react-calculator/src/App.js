import { useState } from "react";

function App() {
  const [clac, setClac] = useState("");
  const [result, setResult] = useState("");

  const ops = ["/", "*", "+", "-", "."];
  const updateClac = (value) => {
    if (
      (ops.includes(value) && clac === "") ||
      (ops.includes(value) && ops.includes(clac.slice(-1)))
    ) {
      return;
    }
    setClac(clac + value);
    if (!ops.includes(value)) {
      setResult(eval(clac + value).toString());
    }
  };
  const equalTo = () => {
    setClac(result);
    setResult("");
  };
  const deleteAll = () => {
    setClac("");
    setResult("");
  };

  const createDigits = () => {
    const digits = [];
    for (let i = 1; i < 10; i++) {
      digits.push(
        <button key={i} onClick={() => updateClac(i.toString())}>
          {i}
        </button>
      );
    }
    return digits;
  };

  return (
    <div className="App">
      <div className="calculator">
        <div className="display">
          {result ? <span>({result})</span> : ""} {clac || "0"}
        </div>
        <div className="operator">
          <button onClick={() => updateClac("/")}>/</button>
          <button onClick={() => updateClac("*")}>*</button>
          <button onClick={() => updateClac("+")}>+</button>
          <button onClick={() => updateClac("-")}>-</button>
          <button onClick={deleteAll}>DEL</button>
        </div>
        <div className="digits">
          {createDigits()}
          <button onClick={() => updateClac(".")}>.</button>
          <button onClick={() => updateClac("0")}>0</button>
          <button onClick={equalTo}>=</button>
        </div>
      </div>
    </div>
  );
}

export default App;
