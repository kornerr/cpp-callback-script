
-- Call already registered modules.
values = env:call("proxy", {"One", "Two"})
env:print(values)

-- Register new module that responds to 'lua' key.
ec = EnvironmentClient.new()

ec.callbackRespondsToKey = function(key)
    env:print({"ec.respondsToKey ", key})
    return key == "lua"
end

ec.callbackCall = function(key, values)
    env:print({"ec.call ", key})
    env:print({"ec.call values "})
    env:print(values)
    for k, v in pairs(values) do
        env:print({k, " -> ", v})
    end
    return {"Z", "A"}
end

-- Add ec as Environment client.
env:addClient(ec)

-- Call upon all the clients.
env:call("lua", {"X", "Y"})
