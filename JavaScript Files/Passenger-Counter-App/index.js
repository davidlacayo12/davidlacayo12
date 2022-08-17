
//document.getelementbyId("count-el").innerText = 5
/*
let firstBatch = 5
let count = firstBatch
console.log(count)  //must initialize variable before referencing it through the console log 

let myAge = 19
console.log(myAge)

let myAge = 19
let humanDogRatio = 7
let myDogAge = myAge * humanDogRatio

console.log(myDogAge)*/
/*function countdown() {
    console.log(5)
    console.log(4)
    console.log(3)
    console.log(2)
    console.log(1)

}
*/
//countdown()

//let lap1=34
//let lap2=33
//let lap3=36

/*function sumlap() {
    console.log(lap1 + lap2 + lap3)
}

sumlap()
*/

// camelCase --> capatilizing the first letter of the first word, but not the second word 
let countEl = document.getElementById("count-el")
let count = 0

function increment() {
    count += 1
    countEl.innerText = count
}

function save() {
    console.log(count)
}


