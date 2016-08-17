// Script for tile filling game


var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");


var clickX = 0
var clickY = 0

var red = 0
var green = 0
var blue = 255
var color = "rgba(" + red + "," + green + "," + blue + ", 1)"

var leftMargin = 250
var topMargin = 40
var boardWidth = 460
var boardHeight = 460

var buttonSpacer = 100
var buttonWidth = (boardWidth - buttonSpacer) / 3
var buttonHeight = buttonWidth / 3

var numColumns = 2
var numRows = 2

var score = numColumns * numRows

red = 255
var color1 = "rgba(" + red + "," + green + "," + blue + ", 1)"
green = 255
var color2 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 0
var color3 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 255
blue = 0
var color4 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 0
green = 0
blue = 255
var color5 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 255
blue = 0
var color6 = "rgba(" + red + "," + green + "," + blue + ", 1)"
var buttonColors = []

buttonColors.push(color1)
buttonColors.push(color2)
buttonColors.push(color3)
buttonColors.push(color4)
buttonColors.push(color5)
buttonColors.push(color6)

var buttons = []
var button1 = {
    leftMargin: leftMargin,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[0]
}
var button2 = {
    leftMargin: leftMargin + buttonWidth + buttonSpacer/2,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[1]
}
var button3 = {
    leftMargin: leftMargin + (buttonWidth + buttonSpacer/2) * 2,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[2]
}
var button4 = {
    leftMargin: leftMargin,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[3]

}
var button5 = {
    leftMargin: leftMargin + buttonWidth + buttonSpacer/2,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[4]
}
var button6 = {
    leftMargin: leftMargin + (buttonWidth + buttonSpacer/2) * 2,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[5]
}

buttons.push(button1)
buttons.push(button2)
buttons.push(button3)
buttons.push(button4)
buttons.push(button5)
buttons.push(button6)


var tileWidth = boardWidth / numColumns
var tileHeight = boardHeight / numRows
var boardTiles = []

for(var i = 0; i < numColumns; i++) {
    for (var j = 0; j < numRows; j++) {
        boardTiles.push({
            leftMargin: leftMargin + i * tileWidth,
            topMargin: topMargin + j * tileHeight,
            color: buttonColors[getRandomInt(0, 5)]
        })
    }
}

/**
 * Returns a random integer between min (inclusive) and max (inclusive)
 * Using Math.round() will give you a non-uniform distribution!
 */
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function drawScore() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Score: "+score, 8, 20);
}


function drawBoard() {
    boardTiles.forEach(function(v, k) {
        ctx.beginPath();
        ctx.rect(v.leftMargin, v.topMargin, tileWidth, tileHeight)
        ctx.fillStyle = v.color
        ctx.fill();
        ctx.closePath();
    })
}

function drawButtons() {

    buttons.forEach(function (v, k) {
        ctx.beginPath()
        ctx.rect(v.leftMargin, v.topMargin, buttonWidth, buttonHeight)
        ctx.fillStyle = v.color
        ctx.fill();
        ctx.closePath() 
    })
   
}

function draw() {
    // drawing code
    ctx.clearRect(0, 0, canvas.width, canvas.height)

    drawBoard()
    drawButtons()

    drawScore()

}

function keyDownHandler(e) {
    console.log("Handler:  ", e.keyCode)
    if(e.keyCode == 39) {
        rightPressed = true;
    }
    else if(e.keyCode == 37) {
        leftPressed = true;
    }
}

function keyUpHandler(e) {
    console.log("upHandler:  ", e.keyCode)
    if(e.keyCode == 39) {
        rightPressed = false;
    }
    else if(e.keyCode == 37) {
        leftPressed = false;
    }
}

function mouseMoveHandler(e) {
    var relativeX = e.clientX - canvas.offsetLeft;
    if(relativeX > 0 && relativeX < canvas.width) {
    }
}

function mouseDownHandler(e) {
    var relativeX = e.clientX - canvas.offsetLeft;
    var relativeY = e.clientY - canvas.offsetTop;

    clickX = relativeX
    clickY = relativeY

    buttonPressDetection()

}

function buttonPressDetection() {
    buttons.forEach(function(v, k) {
        if (clickX > v.leftMargin && clickX < v.leftMargin + buttonWidth &&
            clickY > v.topMargin && clickY < v.topMargin + buttonHeight) {

            registerClick(k)
        }

    })
}

function registerClick(idx) {
    console.log("RegisterClick, calling...")
    var tiles = getArrayOfMatchingTiles()

    //ASSERT:  Clicked button[idx].  Set color to match
    tiles.forEach(function(v, k) {
        boardTiles[v].color = buttons[idx].color
    })

    score--
}

function getArrayOfMatchingTiles() {

    // Start at boardTiles[0]
    var rtn = [0]
    var clr = boardTiles[0].color
    
    if(boardTiles[1].color == clr) {
        rtn.push(1)
        if (boardTiles[3].color == clr) {
            rtn.push(3)
        }
    }
    if (boardTiles[2].color == clr) {
        rtn.push(2)
        if (boardTiles[3].color == clr) {
            rtn.push(3)
        }
    }

    console.log("Return: ", rtn)

    uniqueArray = rtn.filter(function(item, pos, self) {
        return self.indexOf(item) == pos;
    })

    console.log("Return: ", uniqueArray)

    return uniqueArray
}


setInterval(draw, 10);

document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousemove", mouseMoveHandler, false);
document.addEventListener("mousedown", mouseDownHandler, false);


ctx.beginPath();
ctx.rect(20, 40, 50, 50);
ctx.fillStyle = "#FF0000";
ctx.fill();
ctx.closePath();

ctx.beginPath();
ctx.arc(240, 160, 20, 0, Math.PI*2, false);
ctx.fillStyle = "green";
ctx.fill();
ctx.closePath();

ctx.beginPath();
ctx.rect(160, 10, 100, 40);
ctx.strokeStyle = "rgba(0, 0, 255, 0.5)";
ctx.stroke();
ctx.closePath();
