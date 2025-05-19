const addon = require("../build/Release/HelloWorld.node");
const hello = new addon.Hello(); // Instantiate the C++ class
console.log(hello.Add(1, 55));
//# sourceMappingURL=index.js.map