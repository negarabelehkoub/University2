function loadEvent() {
    document.getElementById("header").innerHTML = "Page Loaded!";
}

function changeEvent() {
    alert("Input field changed!");
}

function keyDownEvent() {
    alert("Key pressed!");
}

function mouseOverEvent() {
    document.getElementById("paragraph").classList.add("highlight");
}

function mouseOutEvent() {
    document.getElementById("paragraph").classList.remove("highlight");
}