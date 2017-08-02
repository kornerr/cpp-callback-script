
-- Call already registered modules.
values = env:call("proxy", {"One", "Two"})
env:print(values)

-- Register new module.
ec = EnvironmentClient.new()

-- Provider respondsToKey method of ec instance with callback.
function customRespondsToKey(key)
    env:print({"ec.respondsToKey", key})
    return false
end
ec:setCallbackRespondsToKey(customRespondsToKey)

-- Add ec as Environment client.
env:addClient(ec)

-- Call upon all the clients.
env:call("lua", {"X", "Y"})
