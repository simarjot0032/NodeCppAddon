const addon = require("../build/Release/HelloWorld.node");

const hello = new addon.Hello();
console.log(hello.Add(1, 55));
