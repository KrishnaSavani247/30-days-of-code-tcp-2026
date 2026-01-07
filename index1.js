const cells = document.querySelectorAll(".cell");
const statusText = document.getElementById("status");

let currentPlayer = "X";
let gameActive = true;

const winPatterns = [
    [0,1,2],[3,4,5],[6,7,8],
    [0,3,6],[1,4,7],[2,5,8],
    [0,4,8],[2,4,6]
];

cells.forEach((cell, index) => {
    cell.addEventListener("click", () => handleClick(cell, index));
});

function handleClick(cell, index) {
    if (cell.textContent !== "" || !gameActive) return;

    cell.textContent = currentPlayer;

    if (checkWin()) {
        statusText.textContent = `Player ${currentPlayer} Wins!`;
        gameActive = false;
        return;
    }

    if (checkDraw()) {
        statusText.textContent = "It's a Draw!";
        statusText.classList.add("draw");
        gameActive = false;
        return;
    }

    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.textContent = `Player ${currentPlayer}'s Turn`;
}

function checkWin() {
    for (let pattern of winPatterns) {
        let [a, b, c] = pattern;
        if (
            cells[a].textContent &&
            cells[a].textContent === cells[b].textContent &&
            cells[a].textContent === cells[c].textContent
        ) {
            cells[a].classList.add("win");
            cells[b].classList.add("win");
            cells[c].classList.add("win");
            return true;
        }
    }
    return false;
}

function checkDraw() {
    return [...cells].every(cell => cell.textContent !== "");
}

function restartGame() {
    currentPlayer = "X";
    gameActive = true;
    statusText.textContent = "Player X's Turn";
    statusText.classList.remove("draw");

    cells.forEach(cell => {
        cell.textContent = "";
        cell.classList.remove("win");
    });
}
