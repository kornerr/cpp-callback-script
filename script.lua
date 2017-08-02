
-- Call already registered modules.
values = env:call("proxy", {"One", "Two"})
env:print(values)

-- Register new module.
ec = EnvironmentClient.new()

---- Try to override respondsToKey method for ec instance.
--function ec:respondsToKey(key)
--    env:print({"ec.respondsToKey", key})
--    return false
--end

-- Add ec as Environment client.
env:addClient(ec)

-- Call upon all the clients.
env:call("lua", {"X", "Y"})
