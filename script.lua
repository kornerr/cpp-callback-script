
-- Print title, type, and values.
function printValues(title, values)
    print("----", title, "----")
    print(values)
    for k, v in pairs(values) do
        print("", k, "->", v)
    end
end

-- Call already registered modules.
values = env:call("proxy", {"One", "Two"})
printValues("Calling 'proxy'", values)

-- Register new module that responds to 'lua' key.
ec = EnvironmentClient.new()

ec.callbackRespondsToKey = function(key)
    return key == "lua"
end

ec.callbackCall = function(key, values)
    printValues("Inside callback", values)
    return {"Z", "A"}
end

-- Add ec as Environment client.
env:addClient(ec)

-- Call newly registered module.
values = env:call("lua", {"X", "Y"})
printValues("Calling 'lua'", values)
