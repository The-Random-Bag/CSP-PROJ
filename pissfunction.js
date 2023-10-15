function piss() {
    console.log("hi")
    let name = prompt("enter name")
    alert("hi " + name + " have this duck")
    let img = document.createElement("img");
    const canvags = document.getElementById("myCanvas");
    const context = canvags.context("2d")
    img.src = "duckload.jpg";

    img.style.border = "10px solid orange";
    img.style.borderRadius = "10px";

    document.body.appendChild(img);
}



