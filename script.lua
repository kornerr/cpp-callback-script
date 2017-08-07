
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

useStrings = true

-- Use strings.
if (useStrings) then
    ec.callbackCall = function(key, values)
        printValues("Inside normal callback", values)
        return values
        --return {"Z", "A"}
    end
-- Use vector.
else
    ec.callbackCallVector = function(key, vector)
        printValues("Inside vector callback", vector.values)
        v = Vector.new()
        v:setValues({"Z", "A"})
        return v
    end
end

-- Add ec as Environment client.
env:addClient(ec)

-- Call newly registered module.
values = env:call("lua", {"X", "Y"})
printValues("Values after calling 'lua'", values)
