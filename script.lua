
-- Call already registered modules.
values = env:call("proxy", {"One", "Two"})
env:print(values)

-- Register new module that responds to 'lua' key.
ec = EnvironmentClient.new()

ec.callbackRespondsToKey = function(key)
    env:print({"ec.respondsToKey ", key})
    return key == "lua"
end

if (false) then
    ec.callbackCall = function(key, values)
        env:print({"ec.call ", key})
        env:print({"ec.call values "})
        env:print(values)
        for k, v in pairs(values) do
            env:print({k, " -> ", v})
        end
        return {"Z", "A"}
    end
end

if (true) then
    ec.callbackCallVector = function(key, vector)
        env:print({"ec.call ", key})
        env:print({"ec.call vector "})
        env:print(vector.strings)
        for k, v in pairs(vector.strings) do
            env:print({k, " -> ", v})
        end
        v = Vector.new()
        v:setStrings({"Z", "A"})
        return v
        --return {"Z", "A"}
        --return vector
    end
end


-- Add ec as Environment client.
env:addClient(ec)

-- Call upon all the clients.
values = env:call("lua", {"X", "Y"})
env:print(values)
