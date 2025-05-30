

const images = {
    goal1: ["../images/goal1.jpg", "../images/goal11.jpg", "../images/goal111.jpg"],
    goal2: ["image4.jpg", "image5.jpg", "image6.jpg"],
    goal3: ["image7.jpg", "image8.jpg", "image9.jpg"]
};


function addImagesToGoal(goalId, imageList) {
    const goalSection = document.getElementById(goalId);
    const imagesContainer = goalSection.querySelector(".images");

    imageList.forEach(image => {
        const img = document.createElement("img");
        img.src = `images/${image}`;
        img.alt = "Ocean Image";
        imagesContainer.appendChild(img);
    });
}

addImagesToGoal("goal1", images.goal1);
addImagesToGoal("goal2", images.goal2);
addImagesToGoal("goal3", images.goal3);
function changeImage(){
    document.getElementById("img_1_hover").src="goal111.jpg"
}