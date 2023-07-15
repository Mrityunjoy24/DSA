// Question 1: What’s the output?
var x = 21;
var girl = function () {
    console.log(x);
    var x = 20;
};
girl();

// Neither 21, nor 20, the result is undefined
// It’s because JavaScript initialization is not hoisted.
// (Why doesn’t it show the global value of 21? The reason is that when the function is executed, it checks that there’s a local x variable present but doesn’t yet declare it, so it won’t look for global one.)

// Question 2: What’s the output?
console.log('start')

setTimeout(() => {
    console.log('setTimeout')
})

Promise.resolve().then(() => {
    console.log('resolve')
})

console.log('end')

// start
// end
// resolve
// setTimeout

// Question 3: What’s the output?
const timer1 = setTimeout(() => {
    console.log('timer1');

    const timer3 = setTimeout(() => {
        console.log('timer3')
    }, 0)
}, 0)

const timer2 = setTimeout(() => {
    console.log('timer2')
}, 0)

console.log('start')


// Question 4: What’s the output?
const promise1 = new Promise((resolve, reject) => {
    console.log(1);
});

promise1.then(() => {
    console.log(3);
});

console.log(4);

//Queestion what is the output?
console.log(1)

const promise2 = new Promise((resolve, reject) => {
    console.log(2)
})

promise1.then(res => {
    console.log(3)
})

const promiseFn = () => (new Promise((resolve, reject) => {
    console.log(4);
    resolve(5)
}))

console.log(6)

promiseFn().then(res => {
    console.log(7)
})

console.log(8)


// var x=21;
function abc(){
    // console.log(x);
    var x=20;
}
abc();