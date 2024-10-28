//1
var CurrentDate=new Date();
var day=CurrentDate.getDate();
var month=CurrentDate.getMonth()+1;
var year= currentDate.getFullYear();
document.write(day+"/"+month+"/"+year)

//2
var currentTime = new Date();
var hours = currentTime.getHours();
var minutes = currentTime.getMinutes();
if (minutes < 10) {
minutes = "0" + minutes;
}
document.write(hours + ":" + minutes)

//3
var currentTime = new Date()
var hours = currentTime.getHours()
var minutes = currentTime.getMinutes();
if (minutes < 10) {
minutes = "0" + minutes;
}
var suffix = "AM";
if (hours >= 12) {
suffix = "PM";
hours = hours - 12;
}
if (hours == 0) {
hours = 12;
}
document.write(hours + ":" + minutes + " " + suffix)